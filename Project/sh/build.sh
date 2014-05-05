rm -rf build
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j8 -lpthread
# function remake(){
# 	clean
# 	newDir
# 	compile
# }

# remake
