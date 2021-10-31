add_executable(main main.cpp)

add_library(Matrix STATIC Matrix.cpp Exception.cpp)

target_link_libraries(main Matrix)