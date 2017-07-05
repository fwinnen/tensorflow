#./tensorflow/contrib/makefile/build_all_linux.sh
rm -rf tfcore-raspberry-armhf-opt
cp -r tensorflow/contrib/makefile/gen tfcore-raspberry-armhf-opt
cd tfcore-raspberry-armhf-opt
rm -rf dep bin host_bin host_obj obj protobuf protobuf-host
cd ..
zip -r  tfcore-raspberry-armhf-opt.zip tfcore-raspberry-armhf-opt
