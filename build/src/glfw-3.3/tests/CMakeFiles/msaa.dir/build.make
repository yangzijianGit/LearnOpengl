# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\svn_zijian\opengl\LearnOpengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\svn_zijian\opengl\LearnOpengl\build

# Include any dependencies generated for this target.
include src/glfw-3.3/tests/CMakeFiles/msaa.dir/depend.make

# Include the progress variables for this target.
include src/glfw-3.3/tests/CMakeFiles/msaa.dir/progress.make

# Include the compile flags for this target's objects.
include src/glfw-3.3/tests/CMakeFiles/msaa.dir/flags.make

src/glfw-3.3/tests/CMakeFiles/msaa.dir/msaa.c.obj: src/glfw-3.3/tests/CMakeFiles/msaa.dir/flags.make
src/glfw-3.3/tests/CMakeFiles/msaa.dir/msaa.c.obj: src/glfw-3.3/tests/CMakeFiles/msaa.dir/includes_C.rsp
src/glfw-3.3/tests/CMakeFiles/msaa.dir/msaa.c.obj: ../src/glfw-3.3/tests/msaa.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\svn_zijian\opengl\LearnOpengl\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/glfw-3.3/tests/CMakeFiles/msaa.dir/msaa.c.obj"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\msaa.dir\msaa.c.obj   -c F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\tests\msaa.c

src/glfw-3.3/tests/CMakeFiles/msaa.dir/msaa.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msaa.dir/msaa.c.i"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\tests\msaa.c > CMakeFiles\msaa.dir\msaa.c.i

src/glfw-3.3/tests/CMakeFiles/msaa.dir/msaa.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msaa.dir/msaa.c.s"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\tests\msaa.c -o CMakeFiles\msaa.dir\msaa.c.s

src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.obj: src/glfw-3.3/tests/CMakeFiles/msaa.dir/flags.make
src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.obj: src/glfw-3.3/tests/CMakeFiles/msaa.dir/includes_C.rsp
src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.obj: ../src/glfw-3.3/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\svn_zijian\opengl\LearnOpengl\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.obj"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\msaa.dir\__\deps\getopt.c.obj   -c F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\deps\getopt.c

src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msaa.dir/__/deps/getopt.c.i"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\deps\getopt.c > CMakeFiles\msaa.dir\__\deps\getopt.c.i

src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msaa.dir/__/deps/getopt.c.s"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\deps\getopt.c -o CMakeFiles\msaa.dir\__\deps\getopt.c.s

src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.obj: src/glfw-3.3/tests/CMakeFiles/msaa.dir/flags.make
src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.obj: src/glfw-3.3/tests/CMakeFiles/msaa.dir/includes_C.rsp
src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.obj: ../src/glfw-3.3/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\svn_zijian\opengl\LearnOpengl\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.obj"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\msaa.dir\__\deps\glad_gl.c.obj   -c F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\deps\glad_gl.c

src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msaa.dir/__/deps/glad_gl.c.i"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\deps\glad_gl.c > CMakeFiles\msaa.dir\__\deps\glad_gl.c.i

src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msaa.dir/__/deps/glad_gl.c.s"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\deps\glad_gl.c -o CMakeFiles\msaa.dir\__\deps\glad_gl.c.s

# Object files for target msaa
msaa_OBJECTS = \
"CMakeFiles/msaa.dir/msaa.c.obj" \
"CMakeFiles/msaa.dir/__/deps/getopt.c.obj" \
"CMakeFiles/msaa.dir/__/deps/glad_gl.c.obj"

# External object files for target msaa
msaa_EXTERNAL_OBJECTS =

src/glfw-3.3/tests/msaa.exe: src/glfw-3.3/tests/CMakeFiles/msaa.dir/msaa.c.obj
src/glfw-3.3/tests/msaa.exe: src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.obj
src/glfw-3.3/tests/msaa.exe: src/glfw-3.3/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.obj
src/glfw-3.3/tests/msaa.exe: src/glfw-3.3/tests/CMakeFiles/msaa.dir/build.make
src/glfw-3.3/tests/msaa.exe: src/glfw-3.3/src/libglfw3.a
src/glfw-3.3/tests/msaa.exe: src/glfw-3.3/tests/CMakeFiles/msaa.dir/linklibs.rsp
src/glfw-3.3/tests/msaa.exe: src/glfw-3.3/tests/CMakeFiles/msaa.dir/objects1.rsp
src/glfw-3.3/tests/msaa.exe: src/glfw-3.3/tests/CMakeFiles/msaa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\svn_zijian\opengl\LearnOpengl\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable msaa.exe"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\msaa.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/glfw-3.3/tests/CMakeFiles/msaa.dir/build: src/glfw-3.3/tests/msaa.exe

.PHONY : src/glfw-3.3/tests/CMakeFiles/msaa.dir/build

src/glfw-3.3/tests/CMakeFiles/msaa.dir/clean:
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && $(CMAKE_COMMAND) -P CMakeFiles\msaa.dir\cmake_clean.cmake
.PHONY : src/glfw-3.3/tests/CMakeFiles/msaa.dir/clean

src/glfw-3.3/tests/CMakeFiles/msaa.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\svn_zijian\opengl\LearnOpengl F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\tests F:\svn_zijian\opengl\LearnOpengl\build F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests\CMakeFiles\msaa.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/glfw-3.3/tests/CMakeFiles/msaa.dir/depend

