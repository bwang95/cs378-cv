
cmake_minimum_required(VERSION 2.8)
project( ComparePhotos )
find_package( OpenCV REQUIRED )
add_executable( ComparePhotos main.cpp )
target_link_libraries( ComparePhotos ${OpenCV_LIBS} )
