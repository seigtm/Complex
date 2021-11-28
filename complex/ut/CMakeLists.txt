set(TEST_NAME ComplexTests)
project(${TEST_NAME})

# Creating test application.
add_executable(${TEST_NAME}
    complexTests.cpp
)

# Linking to tested library.
target_link_libraries(${TEST_NAME} PRIVATE
    Complex
)

# Linking to Google Test Framework.
target_link_libraries(${TEST_NAME} PRIVATE
    gtest
    gtest_main
)

# Creating target to run test during compilation.
add_custom_target(Run_${TEST_NAME}
    COMMAND ${TEST_NAME}
    COMMENT "Running ${TEST_NAME}..."
)
