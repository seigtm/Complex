# CMake basic setup.
cmake_minimum_required(VERSION 3.5)
project(ComplexTests VERSION 1.1.0 LANGUAGES CXX)
message("!- Project: " ${PROJECT_NAME})

# C++ 17 standart required.
set(CMAKE_CXX_STANDARD 17)

# Get conan packages (gtest) and conan CMake commands.
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# Setup all the CMake variables by target.
# Activate the call to the macro conan_target_link_libraries().
conan_basic_setup(TARGETS)

# Add 'main' and 'tests' sources to the main executable.
add_executable(main src/main.cpp src/ut/complexTests.cpp)

# Specifies include directories to use when compiling a given target.
target_include_directories(main
        PUBLIC
            ${PROJECT_SOURCE_DIR}/complex
            ${PROJECT_SOURCE_DIR}/src/ut
)

# Add the 'complex' subdirectory to the build.
add_subdirectory(complex)

# Link all libraries to the executable.
target_link_libraries(main PRIVATE complex CONAN_PKG::gtest)

message("!- Conan libs: " ${CONAN_LIBS})

if (CMAKE_BUILD_TYPE MATCHES Debug)
    # Turn off optimization for non-skewed coverage reports.
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0")
    # Use CodeCoverage for coverage reports.
    include(${PROJECT_SOURCE_DIR}/cmake/CodeCoverage.cmake)
    append_coverage_compiler_flags()
    setup_target_for_coverage_gcovr_html(NAME maincov EXECUTABLE main)
ENDIF()
