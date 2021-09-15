# CMake basic setup.
cmake_minimum_required(VERSION 3.5)
project(Complex VERSION 1.0.0 LANGUAGES CXX)
message("!- Project: " ${PROJECT_NAME})

# Turn on symbol export to make the shared library.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
# Make the shared 'complex' library.
add_library(complex SHARED complex.hpp complex.cpp)
