include_directories(${BASE64_INCLUDE_DIR})

add_subdirectory(googletest)

add_executable(test test.cpp)

target_link_libraries(test Base64 gtest gtest_main)