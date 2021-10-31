add_executable(main main.cpp)

add_library(Matrix STATIC Matrix.cpp Exception.cpp)

add_library(Print STATIC GeneralPrint.cpp PrintMatrixConsole.cpp)

target_link_libraries(main Matrix Print)
