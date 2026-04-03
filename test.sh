./make_all.sh
./getlibmach.sh
mv *a src
cd test
make > /dev/null
./rttest
echo
./ctest
echo 
./mtest
make clean > /dev/null
cd ..
cd src
make clean > /dev/null
rm -rf *.a
cd ..
rm -rd *.a
