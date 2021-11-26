message("MODE=${MODE}")

set(MATRIX_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Matrix/include)

include_directories(${MATRIX_INCLUDE_DIR})

add_subdirectory(Matrix)

add_subdirectory(test)

add_executable(main main.cpp)

target_link_libraries(main Print${MODE})