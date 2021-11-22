# CMake basic setup.
cmake_minimum_required(VERSION 3.5)
project(ComplexExample VERSION 1.5.0 LANGUAGES CXX)

# Build shared gtest library.
if (NOT BUILD_SHARED_LIBS)
    set(BUILD_SHARED_LIBS ON)
endif()

# C++ 17 standart required.
set(CMAKE_CXX_STANDARD 17)

# Add subdirectories to the build.
add_subdirectory(complex)
add_subdirectory(googletest)

# Add 'main' source to the main executable.
add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
)

# Link Complex lib to the executable.
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    Complex
)

# Before create "main" build target "Run_ComplexTests".
add_dependencies(${CMAKE_PROJECT_NAME} Run_ComplexTests)
