# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:/svn_zijian/opengl/LearnOpengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:/svn_zijian/opengl/LearnOpengl/build

# Include any dependencies generated for this target.
include src/glfw-3.3/tests/CMakeFiles/tearing.dir/depend.make

# Include the progress variables for this target.
include src/glfw-3.3/tests/CMakeFiles/tearing.dir/progress.make

# Include the compile flags for this target's objects.
include src/glfw-3.3/tests/CMakeFiles/tearing.dir/flags.make

src/glfw-3.3/tests/CMakeFiles/tearing.dir/tearing.c.obj: src/glfw-3.3/tests/CMakeFiles/tearing.dir/flags.make
src/glfw-3.3/tests/CMakeFiles/tearing.dir/tearing.c.obj: src/glfw-3.3/tests/CMakeFiles/tearing.dir/includes_C.rsp
src/glfw-3.3/tests/CMakeFiles/tearing.dir/tearing.c.obj: ../src/glfw-3.3/tests/tearing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:/svn_zijian/opengl/LearnOpengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/glfw-3.3/tests/CMakeFiles/tearing.dir/tearing.c.obj"
	cd F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests && "D:/Program Files (x86)/mingw64/bin/x86_64-w64-mingw32-gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tearing.dir/tearing.c.obj   -c F:/svn_zijian/opengl/LearnOpengl/src/glfw-3.3/tests/tearing.c

src/glfw-3.3/tests/CMakeFiles/tearing.dir/tearing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/tearing.c.i"
	cd F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests && "D:/Program Files (x86)/mingw64/bin/x86_64-w64-mingw32-gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:/svn_zijian/opengl/LearnOpengl/src/glfw-3.3/tests/tearing.c > CMakeFiles/tearing.dir/tearing.c.i

src/glfw-3.3/tests/CMakeFiles/tearing.dir/tearing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/tearing.c.s"
	cd F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests && "D:/Program Files (x86)/mingw64/bin/x86_64-w64-mingw32-gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:/svn_zijian/opengl/LearnOpengl/src/glfw-3.3/tests/tearing.c -o CMakeFiles/tearing.dir/tearing.c.s

src/glfw-3.3/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj: src/glfw-3.3/tests/CMakeFiles/tearing.dir/flags.make
src/glfw-3.3/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj: src/glfw-3.3/tests/CMakeFiles/tearing.dir/includes_C.rsp
src/glfw-3.3/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj: ../src/glfw-3.3/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:/svn_zijian/opengl/LearnOpengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/glfw-3.3/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj"
	cd F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests && "D:/Program Files (x86)/mingw64/bin/x86_64-w64-mingw32-gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj   -c F:/svn_zijian/opengl/LearnOpengl/src/glfw-3.3/deps/glad_gl.c

src/glfw-3.3/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/__/deps/glad_gl.c.i"
	cd F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests && "D:/Program Files (x86)/mingw64/bin/x86_64-w64-mingw32-gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:/svn_zijian/opengl/LearnOpengl/src/glfw-3.3/deps/glad_gl.c > CMakeFiles/tearing.dir/__/deps/glad_gl.c.i

src/glfw-3.3/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/__/deps/glad_gl.c.s"
	cd F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests && "D:/Program Files (x86)/mingw64/bin/x86_64-w64-mingw32-gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:/svn_zijian/opengl/LearnOpengl/src/glfw-3.3/deps/glad_gl.c -o CMakeFiles/tearing.dir/__/deps/glad_gl.c.s

# Object files for target tearing
tearing_OBJECTS = \
"CMakeFiles/tearing.dir/tearing.c.obj" \
"CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj"

# External object files for target tearing
tearing_EXTERNAL_OBJECTS =

src/glfw-3.3/tests/tearing.exe: src/glfw-3.3/tests/CMakeFiles/tearing.dir/tearing.c.obj
src/glfw-3.3/tests/tearing.exe: src/glfw-3.3/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj
src/glfw-3.3/tests/tearing.exe: src/glfw-3.3/tests/CMakeFiles/tearing.dir/build.make
src/glfw-3.3/tests/tearing.exe: src/glfw-3.3/src/libglfw3.a
src/glfw-3.3/tests/tearing.exe: src/glfw-3.3/tests/CMakeFiles/tearing.dir/linklibs.rsp
src/glfw-3.3/tests/tearing.exe: src/glfw-3.3/tests/CMakeFiles/tearing.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:/svn_zijian/opengl/LearnOpengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable tearing.exe"
	cd F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests && "C:/Program Files/CMake/bin/cmake.exe" -E remove -f CMakeFiles/tearing.dir/objects.a
	cd F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests && "D:/Program Files (x86)/mingw64/bin/ar.exe" cr CMakeFiles/tearing.dir/objects.a @CMakeFiles/tearing.dir/objects1.rsp
	cd F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests && "D:/Program Files (x86)/mingw64/bin/x86_64-w64-mingw32-gcc.exe" -g  -mwindows -Wl,--whole-archive CMakeFiles/tearing.dir/objects.a -Wl,--no-whole-archive  -o tearing.exe -Wl,--out-implib,libtearing.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/tearing.dir/linklibs.rsp

# Rule to build all files generated by this target.
src/glfw-3.3/tests/CMakeFiles/tearing.dir/build: src/glfw-3.3/tests/tearing.exe

.PHONY : src/glfw-3.3/tests/CMakeFiles/tearing.dir/build

src/glfw-3.3/tests/CMakeFiles/tearing.dir/clean:
	cd F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests && $(CMAKE_COMMAND) -P CMakeFiles/tearing.dir/cmake_clean.cmake
.PHONY : src/glfw-3.3/tests/CMakeFiles/tearing.dir/clean

src/glfw-3.3/tests/CMakeFiles/tearing.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" F:/svn_zijian/opengl/LearnOpengl F:/svn_zijian/opengl/LearnOpengl/src/glfw-3.3/tests F:/svn_zijian/opengl/LearnOpengl/build F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests F:/svn_zijian/opengl/LearnOpengl/build/src/glfw-3.3/tests/CMakeFiles/tearing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/glfw-3.3/tests/CMakeFiles/tearing.dir/depend

