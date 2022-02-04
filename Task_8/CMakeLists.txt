set(POLISH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Polish/include)
set(EBASH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/EBash/include)

include_directories(${POLISH_INCLUDE_DIR})
include_directories(${EBASH_INCLUDE_DIR})

add_subdirectory(Polish)
add_subdirectory(EBash)

add_subdirectory(tests)

add_executable(main main.cpp)

target_link_libraries(main Base64)