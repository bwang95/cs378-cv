
cmake_minimum_required(VERSION 2.8)
project( GrayScale)
find_package(OpenCV REQUIRED)
add_executable( GrayScale main.cpp)
target_link_libraries( GrayScale ${OpenCV_LIBS})

