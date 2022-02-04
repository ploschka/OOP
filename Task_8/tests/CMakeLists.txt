include_directories(${POLISH_INCLUDE_DIR})

add_subdirectory(googletest)

add_executable(test test.cpp)

target_link_libraries(test Polish gtest gtest_main)