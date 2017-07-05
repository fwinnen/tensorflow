./tensorflow/contrib/makefile/build_all_android.sh
rm -rf tfcore-android-armeabi-v7a-opt
cp -r tensorflow/contrib/makefile/gen tfcore-android-armeabi-v7a-opt
cd tfcore-android-armeabi-v7a-opt
rm -rf dep bin host_bin host_obj obj protobuf protobuf-host
cd ..
zip -r  tfcore-android-armeabi-v7a-opt.zip tfcore-android-armeabi-v7a-opt
