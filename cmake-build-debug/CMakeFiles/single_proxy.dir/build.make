# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/alex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/projects/single_proxy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/projects/single_proxy/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/single_proxy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/single_proxy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/single_proxy.dir/flags.make

CMakeFiles/single_proxy.dir/CacheEntry.cpp.o: CMakeFiles/single_proxy.dir/flags.make
CMakeFiles/single_proxy.dir/CacheEntry.cpp.o: ../CacheEntry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/projects/single_proxy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/single_proxy.dir/CacheEntry.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_proxy.dir/CacheEntry.cpp.o -c /home/alex/projects/single_proxy/CacheEntry.cpp

CMakeFiles/single_proxy.dir/CacheEntry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_proxy.dir/CacheEntry.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/projects/single_proxy/CacheEntry.cpp > CMakeFiles/single_proxy.dir/CacheEntry.cpp.i

CMakeFiles/single_proxy.dir/CacheEntry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_proxy.dir/CacheEntry.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/projects/single_proxy/CacheEntry.cpp -o CMakeFiles/single_proxy.dir/CacheEntry.cpp.s

CMakeFiles/single_proxy.dir/Client.cpp.o: CMakeFiles/single_proxy.dir/flags.make
CMakeFiles/single_proxy.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/projects/single_proxy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/single_proxy.dir/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_proxy.dir/Client.cpp.o -c /home/alex/projects/single_proxy/Client.cpp

CMakeFiles/single_proxy.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_proxy.dir/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/projects/single_proxy/Client.cpp > CMakeFiles/single_proxy.dir/Client.cpp.i

CMakeFiles/single_proxy.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_proxy.dir/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/projects/single_proxy/Client.cpp -o CMakeFiles/single_proxy.dir/Client.cpp.s

CMakeFiles/single_proxy.dir/http_parser.c.o: CMakeFiles/single_proxy.dir/flags.make
CMakeFiles/single_proxy.dir/http_parser.c.o: ../http_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/projects/single_proxy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/single_proxy.dir/http_parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/single_proxy.dir/http_parser.c.o   -c /home/alex/projects/single_proxy/http_parser.c

CMakeFiles/single_proxy.dir/http_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/single_proxy.dir/http_parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alex/projects/single_proxy/http_parser.c > CMakeFiles/single_proxy.dir/http_parser.c.i

CMakeFiles/single_proxy.dir/http_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/single_proxy.dir/http_parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alex/projects/single_proxy/http_parser.c -o CMakeFiles/single_proxy.dir/http_parser.c.s

CMakeFiles/single_proxy.dir/main.cpp.o: CMakeFiles/single_proxy.dir/flags.make
CMakeFiles/single_proxy.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/projects/single_proxy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/single_proxy.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_proxy.dir/main.cpp.o -c /home/alex/projects/single_proxy/main.cpp

CMakeFiles/single_proxy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_proxy.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/projects/single_proxy/main.cpp > CMakeFiles/single_proxy.dir/main.cpp.i

CMakeFiles/single_proxy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_proxy.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/projects/single_proxy/main.cpp -o CMakeFiles/single_proxy.dir/main.cpp.s

CMakeFiles/single_proxy.dir/MyProxy.cpp.o: CMakeFiles/single_proxy.dir/flags.make
CMakeFiles/single_proxy.dir/MyProxy.cpp.o: ../MyProxy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/projects/single_proxy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/single_proxy.dir/MyProxy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_proxy.dir/MyProxy.cpp.o -c /home/alex/projects/single_proxy/MyProxy.cpp

CMakeFiles/single_proxy.dir/MyProxy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_proxy.dir/MyProxy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/projects/single_proxy/MyProxy.cpp > CMakeFiles/single_proxy.dir/MyProxy.cpp.i

CMakeFiles/single_proxy.dir/MyProxy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_proxy.dir/MyProxy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/projects/single_proxy/MyProxy.cpp -o CMakeFiles/single_proxy.dir/MyProxy.cpp.s

CMakeFiles/single_proxy.dir/parser.cpp.o: CMakeFiles/single_proxy.dir/flags.make
CMakeFiles/single_proxy.dir/parser.cpp.o: ../parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/projects/single_proxy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/single_proxy.dir/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_proxy.dir/parser.cpp.o -c /home/alex/projects/single_proxy/parser.cpp

CMakeFiles/single_proxy.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_proxy.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/projects/single_proxy/parser.cpp > CMakeFiles/single_proxy.dir/parser.cpp.i

CMakeFiles/single_proxy.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_proxy.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/projects/single_proxy/parser.cpp -o CMakeFiles/single_proxy.dir/parser.cpp.s

CMakeFiles/single_proxy.dir/Selector.cpp.o: CMakeFiles/single_proxy.dir/flags.make
CMakeFiles/single_proxy.dir/Selector.cpp.o: ../Selector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/projects/single_proxy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/single_proxy.dir/Selector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_proxy.dir/Selector.cpp.o -c /home/alex/projects/single_proxy/Selector.cpp

CMakeFiles/single_proxy.dir/Selector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_proxy.dir/Selector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/projects/single_proxy/Selector.cpp > CMakeFiles/single_proxy.dir/Selector.cpp.i

CMakeFiles/single_proxy.dir/Selector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_proxy.dir/Selector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/projects/single_proxy/Selector.cpp -o CMakeFiles/single_proxy.dir/Selector.cpp.s

CMakeFiles/single_proxy.dir/Server.cpp.o: CMakeFiles/single_proxy.dir/flags.make
CMakeFiles/single_proxy.dir/Server.cpp.o: ../Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/projects/single_proxy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/single_proxy.dir/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_proxy.dir/Server.cpp.o -c /home/alex/projects/single_proxy/Server.cpp

CMakeFiles/single_proxy.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_proxy.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/projects/single_proxy/Server.cpp > CMakeFiles/single_proxy.dir/Server.cpp.i

CMakeFiles/single_proxy.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_proxy.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/projects/single_proxy/Server.cpp -o CMakeFiles/single_proxy.dir/Server.cpp.s

# Object files for target single_proxy
single_proxy_OBJECTS = \
"CMakeFiles/single_proxy.dir/CacheEntry.cpp.o" \
"CMakeFiles/single_proxy.dir/Client.cpp.o" \
"CMakeFiles/single_proxy.dir/http_parser.c.o" \
"CMakeFiles/single_proxy.dir/main.cpp.o" \
"CMakeFiles/single_proxy.dir/MyProxy.cpp.o" \
"CMakeFiles/single_proxy.dir/parser.cpp.o" \
"CMakeFiles/single_proxy.dir/Selector.cpp.o" \
"CMakeFiles/single_proxy.dir/Server.cpp.o"

# External object files for target single_proxy
single_proxy_EXTERNAL_OBJECTS =

single_proxy: CMakeFiles/single_proxy.dir/CacheEntry.cpp.o
single_proxy: CMakeFiles/single_proxy.dir/Client.cpp.o
single_proxy: CMakeFiles/single_proxy.dir/http_parser.c.o
single_proxy: CMakeFiles/single_proxy.dir/main.cpp.o
single_proxy: CMakeFiles/single_proxy.dir/MyProxy.cpp.o
single_proxy: CMakeFiles/single_proxy.dir/parser.cpp.o
single_proxy: CMakeFiles/single_proxy.dir/Selector.cpp.o
single_proxy: CMakeFiles/single_proxy.dir/Server.cpp.o
single_proxy: CMakeFiles/single_proxy.dir/build.make
single_proxy: CMakeFiles/single_proxy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/projects/single_proxy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable single_proxy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/single_proxy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/single_proxy.dir/build: single_proxy

.PHONY : CMakeFiles/single_proxy.dir/build

CMakeFiles/single_proxy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/single_proxy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/single_proxy.dir/clean

CMakeFiles/single_proxy.dir/depend:
	cd /home/alex/projects/single_proxy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/projects/single_proxy /home/alex/projects/single_proxy /home/alex/projects/single_proxy/cmake-build-debug /home/alex/projects/single_proxy/cmake-build-debug /home/alex/projects/single_proxy/cmake-build-debug/CMakeFiles/single_proxy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/single_proxy.dir/depend

