# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andy/opencv_projects/GrayScale/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andy/opencv_projects/GrayScale/build

# Include any dependencies generated for this target.
include CMakeFiles/GrayScale.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GrayScale.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GrayScale.dir/flags.make

CMakeFiles/GrayScale.dir/main.cpp.o: CMakeFiles/GrayScale.dir/flags.make
CMakeFiles/GrayScale.dir/main.cpp.o: /home/andy/opencv_projects/GrayScale/src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/andy/opencv_projects/GrayScale/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/GrayScale.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GrayScale.dir/main.cpp.o -c /home/andy/opencv_projects/GrayScale/src/main.cpp

CMakeFiles/GrayScale.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GrayScale.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/andy/opencv_projects/GrayScale/src/main.cpp > CMakeFiles/GrayScale.dir/main.cpp.i

CMakeFiles/GrayScale.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GrayScale.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/andy/opencv_projects/GrayScale/src/main.cpp -o CMakeFiles/GrayScale.dir/main.cpp.s

CMakeFiles/GrayScale.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/GrayScale.dir/main.cpp.o.requires

CMakeFiles/GrayScale.dir/main.cpp.o.provides: CMakeFiles/GrayScale.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/GrayScale.dir/build.make CMakeFiles/GrayScale.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/GrayScale.dir/main.cpp.o.provides

CMakeFiles/GrayScale.dir/main.cpp.o.provides.build: CMakeFiles/GrayScale.dir/main.cpp.o

# Object files for target GrayScale
GrayScale_OBJECTS = \
"CMakeFiles/GrayScale.dir/main.cpp.o"

# External object files for target GrayScale
GrayScale_EXTERNAL_OBJECTS =

GrayScale: CMakeFiles/GrayScale.dir/main.cpp.o
GrayScale: /opt/ros/hydro/lib/libopencv_calib3d.so
GrayScale: /opt/ros/hydro/lib/libopencv_contrib.so
GrayScale: /opt/ros/hydro/lib/libopencv_core.so
GrayScale: /opt/ros/hydro/lib/libopencv_features2d.so
GrayScale: /opt/ros/hydro/lib/libopencv_flann.so
GrayScale: /opt/ros/hydro/lib/libopencv_gpu.so
GrayScale: /opt/ros/hydro/lib/libopencv_highgui.so
GrayScale: /opt/ros/hydro/lib/libopencv_imgproc.so
GrayScale: /opt/ros/hydro/lib/libopencv_legacy.so
GrayScale: /opt/ros/hydro/lib/libopencv_ml.so
GrayScale: /opt/ros/hydro/lib/libopencv_nonfree.so
GrayScale: /opt/ros/hydro/lib/libopencv_objdetect.so
GrayScale: /opt/ros/hydro/lib/libopencv_photo.so
GrayScale: /opt/ros/hydro/lib/libopencv_stitching.so
GrayScale: /opt/ros/hydro/lib/libopencv_superres.so
GrayScale: /opt/ros/hydro/lib/libopencv_ts.so
GrayScale: /opt/ros/hydro/lib/libopencv_video.so
GrayScale: /opt/ros/hydro/lib/libopencv_videostab.so
GrayScale: CMakeFiles/GrayScale.dir/build.make
GrayScale: CMakeFiles/GrayScale.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable GrayScale"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GrayScale.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GrayScale.dir/build: GrayScale
.PHONY : CMakeFiles/GrayScale.dir/build

CMakeFiles/GrayScale.dir/requires: CMakeFiles/GrayScale.dir/main.cpp.o.requires
.PHONY : CMakeFiles/GrayScale.dir/requires

CMakeFiles/GrayScale.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GrayScale.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GrayScale.dir/clean

CMakeFiles/GrayScale.dir/depend:
	cd /home/andy/opencv_projects/GrayScale/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andy/opencv_projects/GrayScale/src /home/andy/opencv_projects/GrayScale/src /home/andy/opencv_projects/GrayScale/build /home/andy/opencv_projects/GrayScale/build /home/andy/opencv_projects/GrayScale/build/CMakeFiles/GrayScale.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GrayScale.dir/depend

