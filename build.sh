cd CornerDetection
rm -rf build
mkdir build
cd build
cmake ../src
make -j8

cd ../../Display
rm -rf build
mkdir build
cd build
cmake ../src
make -j8

cd ../../FeatureDetection
rm -rf build
mkdir build
cd build
cmake ../src
make -j8

cd ../../GrayScale
rm -rf build
mkdir build
cd build
cmake ../src
make -j8