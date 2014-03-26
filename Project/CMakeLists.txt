
cmake_minimum_required(VERSION 2.8)
project( Project )
find_package( OpenCV REQUIRED )
SET(exec_SRC)
add_subdirectory(src)
add_executable( Project ${exec_SRC})
target_link_libraries( Project ${OpenCV_LIBS} )
