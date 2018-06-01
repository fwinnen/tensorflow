#ifndef KINEMIC_TF_CLASSIFIER_H_ 
#define KINEMIC_TF_CLASSIFIER_H_

#include <memory>
#include <string>

namespace kinemic {
	class TF_Classifier {
	public:
		TF_Classifier(const std::string& graph, const std::string& input_layer="reshape_3_input", const std::string& output_layer="prediction/Softmax");
		TF_Classifier();
		bool run();
		float* input_buffer();
		const float* output_buffer() const;
		const std::string& getID() const;

	private:
		/* PIMPL idiom: http://oliora.github.io/2015/12/29/pimpl-and-rule-of-zero.html#pimpl-without-special-members-defined */
		class Impl;
		std::unique_ptr<Impl, void (*)(Impl *)> impl_;
	};
} // end namespace kinemic

#endif // KINEMIC_TF_CLASSIFIER_H_
