# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjV2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjV2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjV2.dir/flags.make

CMakeFiles/ProjV2.dir/main.c.obj: CMakeFiles/ProjV2.dir/flags.make
CMakeFiles/ProjV2.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ProjV2.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjV2.dir\main.c.obj   -c C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\main.c

CMakeFiles/ProjV2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjV2.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\main.c > CMakeFiles\ProjV2.dir\main.c.i

CMakeFiles/ProjV2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjV2.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\main.c -o CMakeFiles\ProjV2.dir\main.c.s

CMakeFiles/ProjV2.dir/main.c.obj.requires:

.PHONY : CMakeFiles/ProjV2.dir/main.c.obj.requires

CMakeFiles/ProjV2.dir/main.c.obj.provides: CMakeFiles/ProjV2.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjV2.dir\build.make CMakeFiles/ProjV2.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/ProjV2.dir/main.c.obj.provides

CMakeFiles/ProjV2.dir/main.c.obj.provides.build: CMakeFiles/ProjV2.dir/main.c.obj


CMakeFiles/ProjV2.dir/list_operations.c.obj: CMakeFiles/ProjV2.dir/flags.make
CMakeFiles/ProjV2.dir/list_operations.c.obj: ../list_operations.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ProjV2.dir/list_operations.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjV2.dir\list_operations.c.obj   -c C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\list_operations.c

CMakeFiles/ProjV2.dir/list_operations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjV2.dir/list_operations.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\list_operations.c > CMakeFiles\ProjV2.dir\list_operations.c.i

CMakeFiles/ProjV2.dir/list_operations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjV2.dir/list_operations.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\list_operations.c -o CMakeFiles\ProjV2.dir\list_operations.c.s

CMakeFiles/ProjV2.dir/list_operations.c.obj.requires:

.PHONY : CMakeFiles/ProjV2.dir/list_operations.c.obj.requires

CMakeFiles/ProjV2.dir/list_operations.c.obj.provides: CMakeFiles/ProjV2.dir/list_operations.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjV2.dir\build.make CMakeFiles/ProjV2.dir/list_operations.c.obj.provides.build
.PHONY : CMakeFiles/ProjV2.dir/list_operations.c.obj.provides

CMakeFiles/ProjV2.dir/list_operations.c.obj.provides.build: CMakeFiles/ProjV2.dir/list_operations.c.obj


CMakeFiles/ProjV2.dir/file_operations.c.obj: CMakeFiles/ProjV2.dir/flags.make
CMakeFiles/ProjV2.dir/file_operations.c.obj: ../file_operations.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ProjV2.dir/file_operations.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjV2.dir\file_operations.c.obj   -c C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\file_operations.c

CMakeFiles/ProjV2.dir/file_operations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjV2.dir/file_operations.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\file_operations.c > CMakeFiles\ProjV2.dir\file_operations.c.i

CMakeFiles/ProjV2.dir/file_operations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjV2.dir/file_operations.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\file_operations.c -o CMakeFiles\ProjV2.dir\file_operations.c.s

CMakeFiles/ProjV2.dir/file_operations.c.obj.requires:

.PHONY : CMakeFiles/ProjV2.dir/file_operations.c.obj.requires

CMakeFiles/ProjV2.dir/file_operations.c.obj.provides: CMakeFiles/ProjV2.dir/file_operations.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjV2.dir\build.make CMakeFiles/ProjV2.dir/file_operations.c.obj.provides.build
.PHONY : CMakeFiles/ProjV2.dir/file_operations.c.obj.provides

CMakeFiles/ProjV2.dir/file_operations.c.obj.provides.build: CMakeFiles/ProjV2.dir/file_operations.c.obj


CMakeFiles/ProjV2.dir/buffer_operations.c.obj: CMakeFiles/ProjV2.dir/flags.make
CMakeFiles/ProjV2.dir/buffer_operations.c.obj: ../buffer_operations.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ProjV2.dir/buffer_operations.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjV2.dir\buffer_operations.c.obj   -c C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\buffer_operations.c

CMakeFiles/ProjV2.dir/buffer_operations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjV2.dir/buffer_operations.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\buffer_operations.c > CMakeFiles\ProjV2.dir\buffer_operations.c.i

CMakeFiles/ProjV2.dir/buffer_operations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjV2.dir/buffer_operations.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\buffer_operations.c -o CMakeFiles\ProjV2.dir\buffer_operations.c.s

CMakeFiles/ProjV2.dir/buffer_operations.c.obj.requires:

.PHONY : CMakeFiles/ProjV2.dir/buffer_operations.c.obj.requires

CMakeFiles/ProjV2.dir/buffer_operations.c.obj.provides: CMakeFiles/ProjV2.dir/buffer_operations.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjV2.dir\build.make CMakeFiles/ProjV2.dir/buffer_operations.c.obj.provides.build
.PHONY : CMakeFiles/ProjV2.dir/buffer_operations.c.obj.provides

CMakeFiles/ProjV2.dir/buffer_operations.c.obj.provides.build: CMakeFiles/ProjV2.dir/buffer_operations.c.obj


CMakeFiles/ProjV2.dir/menu_handler.c.obj: CMakeFiles/ProjV2.dir/flags.make
CMakeFiles/ProjV2.dir/menu_handler.c.obj: ../menu_handler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ProjV2.dir/menu_handler.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjV2.dir\menu_handler.c.obj   -c C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\menu_handler.c

CMakeFiles/ProjV2.dir/menu_handler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjV2.dir/menu_handler.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\menu_handler.c > CMakeFiles\ProjV2.dir\menu_handler.c.i

CMakeFiles/ProjV2.dir/menu_handler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjV2.dir/menu_handler.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\menu_handler.c -o CMakeFiles\ProjV2.dir\menu_handler.c.s

CMakeFiles/ProjV2.dir/menu_handler.c.obj.requires:

.PHONY : CMakeFiles/ProjV2.dir/menu_handler.c.obj.requires

CMakeFiles/ProjV2.dir/menu_handler.c.obj.provides: CMakeFiles/ProjV2.dir/menu_handler.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjV2.dir\build.make CMakeFiles/ProjV2.dir/menu_handler.c.obj.provides.build
.PHONY : CMakeFiles/ProjV2.dir/menu_handler.c.obj.provides

CMakeFiles/ProjV2.dir/menu_handler.c.obj.provides.build: CMakeFiles/ProjV2.dir/menu_handler.c.obj


CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj: CMakeFiles/ProjV2.dir/flags.make
CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj: ../adjuvant_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjV2.dir\adjuvant_functions.c.obj   -c C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\adjuvant_functions.c

CMakeFiles/ProjV2.dir/adjuvant_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjV2.dir/adjuvant_functions.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\adjuvant_functions.c > CMakeFiles\ProjV2.dir\adjuvant_functions.c.i

CMakeFiles/ProjV2.dir/adjuvant_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjV2.dir/adjuvant_functions.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\adjuvant_functions.c -o CMakeFiles\ProjV2.dir\adjuvant_functions.c.s

CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj.requires:

.PHONY : CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj.requires

CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj.provides: CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj.requires
	$(MAKE) -f CMakeFiles\ProjV2.dir\build.make CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj.provides.build
.PHONY : CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj.provides

CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj.provides.build: CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj


# Object files for target ProjV2
ProjV2_OBJECTS = \
"CMakeFiles/ProjV2.dir/main.c.obj" \
"CMakeFiles/ProjV2.dir/list_operations.c.obj" \
"CMakeFiles/ProjV2.dir/file_operations.c.obj" \
"CMakeFiles/ProjV2.dir/buffer_operations.c.obj" \
"CMakeFiles/ProjV2.dir/menu_handler.c.obj" \
"CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj"

# External object files for target ProjV2
ProjV2_EXTERNAL_OBJECTS =

ProjV2.exe: CMakeFiles/ProjV2.dir/main.c.obj
ProjV2.exe: CMakeFiles/ProjV2.dir/list_operations.c.obj
ProjV2.exe: CMakeFiles/ProjV2.dir/file_operations.c.obj
ProjV2.exe: CMakeFiles/ProjV2.dir/buffer_operations.c.obj
ProjV2.exe: CMakeFiles/ProjV2.dir/menu_handler.c.obj
ProjV2.exe: CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj
ProjV2.exe: CMakeFiles/ProjV2.dir/build.make
ProjV2.exe: CMakeFiles/ProjV2.dir/linklibs.rsp
ProjV2.exe: CMakeFiles/ProjV2.dir/objects1.rsp
ProjV2.exe: CMakeFiles/ProjV2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable ProjV2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ProjV2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjV2.dir/build: ProjV2.exe

.PHONY : CMakeFiles/ProjV2.dir/build

CMakeFiles/ProjV2.dir/requires: CMakeFiles/ProjV2.dir/main.c.obj.requires
CMakeFiles/ProjV2.dir/requires: CMakeFiles/ProjV2.dir/list_operations.c.obj.requires
CMakeFiles/ProjV2.dir/requires: CMakeFiles/ProjV2.dir/file_operations.c.obj.requires
CMakeFiles/ProjV2.dir/requires: CMakeFiles/ProjV2.dir/buffer_operations.c.obj.requires
CMakeFiles/ProjV2.dir/requires: CMakeFiles/ProjV2.dir/menu_handler.c.obj.requires
CMakeFiles/ProjV2.dir/requires: CMakeFiles/ProjV2.dir/adjuvant_functions.c.obj.requires

.PHONY : CMakeFiles/ProjV2.dir/requires

CMakeFiles/ProjV2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProjV2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ProjV2.dir/clean

CMakeFiles/ProjV2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\cmake-build-debug C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\cmake-build-debug C:\Users\sysoper\Desktop\dev\Michal-Rzepka-gr12-repo\Projekt\cmake-build-debug\CMakeFiles\ProjV2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjV2.dir/depend

