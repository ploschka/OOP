set(BASE64_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Base64/include)

include_directories(${BASE64_INCLUDE_DIR})

add_subdirectory(Base64)

add_subdirectory(tests)

add_executable(main main.cpp)

target_link_libraries(main Base64)