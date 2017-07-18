./tensorflow/contrib/makefile/build_all_linux.sh 
rm -rf tfcore-linux-x86_64-opt
cp -r tensorflow/contrib/makefile/gen tfcore-linux-x86_64-opt
cd tfcore-linux-x86_64-opt
rm -rf dep bin host_bin host_obj obj protobuf protobuf-host
cd ..
zip -r  tfcore-linux-x86_64-opt.zip tfcore-linux-x86_64-opt
