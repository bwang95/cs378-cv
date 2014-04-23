rm -rf build
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j8
# function remake(){
# 	clean
# 	newDir
# 	compile
# }

# remake
