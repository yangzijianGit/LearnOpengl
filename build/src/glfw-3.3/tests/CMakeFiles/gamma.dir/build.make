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
include src/glfw-3.3/tests/CMakeFiles/gamma.dir/depend.make

# Include the progress variables for this target.
include src/glfw-3.3/tests/CMakeFiles/gamma.dir/progress.make

# Include the compile flags for this target's objects.
include src/glfw-3.3/tests/CMakeFiles/gamma.dir/flags.make

src/glfw-3.3/tests/CMakeFiles/gamma.dir/gamma.c.obj: src/glfw-3.3/tests/CMakeFiles/gamma.dir/flags.make
src/glfw-3.3/tests/CMakeFiles/gamma.dir/gamma.c.obj: src/glfw-3.3/tests/CMakeFiles/gamma.dir/includes_C.rsp
src/glfw-3.3/tests/CMakeFiles/gamma.dir/gamma.c.obj: ../src/glfw-3.3/tests/gamma.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\svn_zijian\opengl\LearnOpengl\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/glfw-3.3/tests/CMakeFiles/gamma.dir/gamma.c.obj"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\gamma.dir\gamma.c.obj   -c F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\tests\gamma.c

src/glfw-3.3/tests/CMakeFiles/gamma.dir/gamma.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gamma.dir/gamma.c.i"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\tests\gamma.c > CMakeFiles\gamma.dir\gamma.c.i

src/glfw-3.3/tests/CMakeFiles/gamma.dir/gamma.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gamma.dir/gamma.c.s"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\tests\gamma.c -o CMakeFiles\gamma.dir\gamma.c.s

src/glfw-3.3/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj: src/glfw-3.3/tests/CMakeFiles/gamma.dir/flags.make
src/glfw-3.3/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj: src/glfw-3.3/tests/CMakeFiles/gamma.dir/includes_C.rsp
src/glfw-3.3/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj: ../src/glfw-3.3/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\svn_zijian\opengl\LearnOpengl\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/glfw-3.3/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\gamma.dir\__\deps\glad_gl.c.obj   -c F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\deps\glad_gl.c

src/glfw-3.3/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gamma.dir/__/deps/glad_gl.c.i"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\deps\glad_gl.c > CMakeFiles\gamma.dir\__\deps\glad_gl.c.i

src/glfw-3.3/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gamma.dir/__/deps/glad_gl.c.s"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && D:\PROGRA~2\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\deps\glad_gl.c -o CMakeFiles\gamma.dir\__\deps\glad_gl.c.s

# Object files for target gamma
gamma_OBJECTS = \
"CMakeFiles/gamma.dir/gamma.c.obj" \
"CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj"

# External object files for target gamma
gamma_EXTERNAL_OBJECTS =

src/glfw-3.3/tests/gamma.exe: src/glfw-3.3/tests/CMakeFiles/gamma.dir/gamma.c.obj
src/glfw-3.3/tests/gamma.exe: src/glfw-3.3/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj
src/glfw-3.3/tests/gamma.exe: src/glfw-3.3/tests/CMakeFiles/gamma.dir/build.make
src/glfw-3.3/tests/gamma.exe: src/glfw-3.3/src/libglfw3.a
src/glfw-3.3/tests/gamma.exe: src/glfw-3.3/tests/CMakeFiles/gamma.dir/linklibs.rsp
src/glfw-3.3/tests/gamma.exe: src/glfw-3.3/tests/CMakeFiles/gamma.dir/objects1.rsp
src/glfw-3.3/tests/gamma.exe: src/glfw-3.3/tests/CMakeFiles/gamma.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\svn_zijian\opengl\LearnOpengl\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable gamma.exe"
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gamma.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/glfw-3.3/tests/CMakeFiles/gamma.dir/build: src/glfw-3.3/tests/gamma.exe

.PHONY : src/glfw-3.3/tests/CMakeFiles/gamma.dir/build

src/glfw-3.3/tests/CMakeFiles/gamma.dir/clean:
	cd /d F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests && $(CMAKE_COMMAND) -P CMakeFiles\gamma.dir\cmake_clean.cmake
.PHONY : src/glfw-3.3/tests/CMakeFiles/gamma.dir/clean

src/glfw-3.3/tests/CMakeFiles/gamma.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\svn_zijian\opengl\LearnOpengl F:\svn_zijian\opengl\LearnOpengl\src\glfw-3.3\tests F:\svn_zijian\opengl\LearnOpengl\build F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests F:\svn_zijian\opengl\LearnOpengl\build\src\glfw-3.3\tests\CMakeFiles\gamma.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/glfw-3.3/tests/CMakeFiles/gamma.dir/depend

