include_directories(${MATRIX_INCLUDE_DIR})

add_subdirectory(googletest)

add_executable(test test.cpp)

target_link_libraries(test Matrix gtest gtest_main)