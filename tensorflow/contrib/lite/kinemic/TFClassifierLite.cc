#define EIGEN_USE_THREADS
#define EIGEN_USE_CUSTOM_THREAD_POOL

#include "tensorflow/contrib/lite/kinemic/tf_classifier.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "tensorflow/contrib/lite/kernels/register.h"
#include "tensorflow/contrib/lite/model.h"

/* PIMPL idiom: http://oliora.github.io/2015/12/29/pimpl-and-rule-of-zero.html#pimpl-without-special-members-defined */

#define LOGE(x) std::cerr << x

namespace kinemic {
    class TF_Classifier::Impl {
    public:
        Impl(const std::string& graph, const std::string& input_layer, const std::string& output_layer) {
            model = tflite::FlatBufferModel::BuildFromFile(graph.c_str());
            if (!model) {
                LOGE("loading model failed");
            } else {
                //LOG(INFO) << "loading model succeeded!";
            }

            tflite::ops::builtin::BuiltinOpResolver resolver;

            tflite::InterpreterBuilder(*model, resolver)(&interpreter);
            if (!interpreter) {
                LOGE("Failed to construct interpreter\n");
            }

            if (interpreter->AllocateTensors() != kTfLiteOk) {
                LOGE("Failed to allocate tensors!");
            }
        }

        bool run() {
            if (interpreter->Invoke() != kTfLiteOk) {
                LOGE("Failed to invoke tflite!\n");
                return false;
            }

            return true;
        }

        float* input_buffer() {
            return interpreter->typed_input_tensor<float>(0);
        }

        const float* output_buffer() const {
            return interpreter->typed_output_tensor<float>(0);
        }

        const std::string& getID() const {
            return ID;
        }

    private:
        std::unique_ptr<tflite::FlatBufferModel> model;
        std::unique_ptr<tflite::Interpreter> interpreter;

        static constexpr size_t kLabels = 20;

        const std::string ID = "lite";
    };

/* interface */
    TF_Classifier::TF_Classifier() : TF_Classifier("data/opt_kinemic_cnn.pb") {}
    TF_Classifier::TF_Classifier(const std::string& graph, const std::string& input_layer, const std::string& output_layer)
            : impl_(new Impl(graph, input_layer, output_layer), [](Impl *impl) { delete impl; })
    {}

    bool TF_Classifier::run() {
        return impl_->run();
    }

    float* TF_Classifier::input_buffer() {
        return impl_->input_buffer();
    }

    const float* TF_Classifier::output_buffer() const {
        return impl_->output_buffer();
    }

    const std::string& TF_Classifier::getID() const {
        return impl_->getID();
    }

}  // end namespace kinemic
