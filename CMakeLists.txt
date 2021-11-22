# CMake basic setup.
cmake_minimum_required(VERSION 3.5)
project(ComplexTests VERSION 1.5.0 LANGUAGES CXX)

# C++ 17 standart required.
set(CMAKE_CXX_STANDARD 17)

# Add subdirectories to the build.
add_subdirectory(complex)
add_subdirectory(googletest)

# Build shared gtest library.
if (NOT BUILD_SHARED_LIBS)
    set(BUILD_SHARED_LIBS ON)
endif()

# Add 'main' and 'tests' sources to the main executable.
add_executable(main
    src/main.cpp
    src/ut/complexTests.cpp
)

# Specifies include directories to use when compiling a given target.
target_include_directories(main PUBLIC
    ${PROJECT_SOURCE_DIR}/complex
    ${PROJECT_SOURCE_DIR}/src/ut
)

# Link all libraries to the executable.
target_link_libraries(main PRIVATE
    Complex
    gtest
)
