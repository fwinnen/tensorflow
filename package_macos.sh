./tensorflow/contrib/makefile/build_all_linux.sh -T
rm -rf tfcore-macos-x86_64-opt
cp -r tensorflow/contrib/makefile/gen tfcore-macos-x86_64-opt
cd tfcore-macos-x86_64-opt
rm -rf dep bin host_bin host_obj obj protobuf protobuf-host
cd ..
zip -r  tfcore-macos-x86_64-opt.zip tfcore-macos-x86_64-opt
