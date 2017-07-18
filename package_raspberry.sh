./tensorflow/contrib/makefile/build_all_pi_cross.sh
rm -rf tfcore-raspberry-armv8-opt
cp -r tensorflow/contrib/makefile/gen tfcore-raspberry-armv8-opt
cd tfcore-raspberry-armv8-opt
rm -rf dep bin host_bin host_obj obj protobuf protobuf-host
cd ..
zip -r  tfcore-raspberry-armv8-opt.zip tfcore-raspberry-armv8-opt
rm -rf tfcore-raspberry-armv8-opt
