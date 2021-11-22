# CMake basic setup.
cmake_minimum_required(VERSION 3.5)
project(Complex VERSION 1.5.0 LANGUAGES CXX)

# C++ 17 standart required.
set(CMAKE_CXX_STANDARD 17)

# Make the shared 'complex' library.
add_subdirectory(ut)
# install(FILES ${CMAKE_CURRENT_LIST_DIR}/complex.hpp DESTINATION "include/complex/")
add_library(${PROJECT_NAME} SHARED complex.hpp complex.cpp)
target_include_directories(${PROJECT_NAME} INTERFACE .)
# install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
