cmake_minimum_required(VERSION "3.20")
project(MedReminder)

# To use this handy cmake file, you'll want to setup CMake.
#
# (Ninja is a personally preferred build system of mine, Make is the default)
#
# Ubuntu / Debian   :: sudo apt-get install cmake make ninja
# Fedora / RHEL     :: sudo rpm install cmake make ninja
# OpenSUSE          :: sudo zypper install cmake make ninja
# Arch Linux        :: sudo pacman -S cmake make ninja
# Windows (MSYS2)   :: pacman -S mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja
# macOS (Homebrew)  :: brew install cmake ninja
#
# Also a compiler like g++ or clang++
#
# Ubuntu / Debian   :: sudo apt-get install g++ (or) clang++
# Fedora / RHEL     :: sudo rpm install g++ (or) clang++
# OpenSUSE          :: sudo zypper install g++ (or) clang++
# Arch Linux        :: sudo pacman -S gcc (or) clang
# Windows (MSYS2)   :: pacman -S mingw-w64-x86_64-gcc (or) mingw-w64-x86_64-clang
# macOS (Homebrew)  :: brew install gcc (or) llvm

# Build Steps
#
# 1. Create a build directory
#    mkdir build && cd build
#
# 2. Run CMake to generate build files
#    cmake -G Ninja ..   * For Ninja (or any preferred build system)
#    cmake ..            * For the default Makefiles
#
# 3. Build the project
#    ninja              * If using Ninja
#    make               * If using Make
#

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(MedReminder ${SOURCE_FILES})