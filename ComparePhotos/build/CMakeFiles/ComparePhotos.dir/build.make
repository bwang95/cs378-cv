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

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/build

# Include any dependencies generated for this target.
include CMakeFiles/ComparePhotos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ComparePhotos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ComparePhotos.dir/flags.make

CMakeFiles/ComparePhotos.dir/main.cpp.o: CMakeFiles/ComparePhotos.dir/flags.make
CMakeFiles/ComparePhotos.dir/main.cpp.o: /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ComparePhotos.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ComparePhotos.dir/main.cpp.o -c /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/src/main.cpp

CMakeFiles/ComparePhotos.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComparePhotos.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/src/main.cpp > CMakeFiles/ComparePhotos.dir/main.cpp.i

CMakeFiles/ComparePhotos.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComparePhotos.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/src/main.cpp -o CMakeFiles/ComparePhotos.dir/main.cpp.s

CMakeFiles/ComparePhotos.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/ComparePhotos.dir/main.cpp.o.requires

CMakeFiles/ComparePhotos.dir/main.cpp.o.provides: CMakeFiles/ComparePhotos.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ComparePhotos.dir/build.make CMakeFiles/ComparePhotos.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ComparePhotos.dir/main.cpp.o.provides

CMakeFiles/ComparePhotos.dir/main.cpp.o.provides.build: CMakeFiles/ComparePhotos.dir/main.cpp.o

# Object files for target ComparePhotos
ComparePhotos_OBJECTS = \
"CMakeFiles/ComparePhotos.dir/main.cpp.o"

# External object files for target ComparePhotos
ComparePhotos_EXTERNAL_OBJECTS =

ComparePhotos: CMakeFiles/ComparePhotos.dir/main.cpp.o
ComparePhotos: CMakeFiles/ComparePhotos.dir/build.make
ComparePhotos: /opt/ros/hydro/lib/libopencv_calib3d.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_contrib.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_core.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_features2d.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_flann.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_gpu.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_highgui.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_imgproc.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_legacy.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_ml.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_nonfree.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_objdetect.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_photo.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_stitching.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_superres.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_ts.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_video.so
ComparePhotos: /opt/ros/hydro/lib/libopencv_videostab.so
ComparePhotos: CMakeFiles/ComparePhotos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ComparePhotos"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ComparePhotos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ComparePhotos.dir/build: ComparePhotos
.PHONY : CMakeFiles/ComparePhotos.dir/build

CMakeFiles/ComparePhotos.dir/requires: CMakeFiles/ComparePhotos.dir/main.cpp.o.requires
.PHONY : CMakeFiles/ComparePhotos.dir/requires

CMakeFiles/ComparePhotos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ComparePhotos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ComparePhotos.dir/clean

CMakeFiles/ComparePhotos.dir/depend:
	cd /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/src /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/src /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/build /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/build /home/brian/Documents/Classes/CS378RobotsLeonetti/cs378-cv/ComparePhotos/build/CMakeFiles/ComparePhotos.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ComparePhotos.dir/depend

