#NDK_ROOT=$ANDROID_NDK_r13b  ./tensorflow/contrib/makefile/build_all_android.sh 
rm -rf tfcore-android-x86-opt
cp -r tensorflow/contrib/makefile/gen tfcore-android-x86-opt
cd tfcore-android-x86-opt
rm -rf dep bin host_bin host_obj obj protobuf protobuf-host
cd ..
zip -r  tfcore-android-x86-opt.zip tfcore-android-x86-opt
