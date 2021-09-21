# CMake basic setup.
cmake_minimum_required(VERSION 3.5)
project(Complex VERSION 1.0.0 LANGUAGES CXX)
message("!- Project: " ${PROJECT_NAME})

# Turn on symbol export to make the shared library.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
# Make the shared 'complex' library.
add_library(complex SHARED complex.hpp complex.cpp)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    # Use CodeCoverage for coverage reports.
    include(${PROJECT_SOURCE_DIR}/../cmake/CodeCoverage.cmake)
    append_coverage_compiler_flags()
    setup_target_for_coverage_gcovr_html(NAME complexcov EXECUTABLE main)
ENDIF()
