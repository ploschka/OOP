add_executable(main main.cpp)

add_library(Matrix SHARED Matrix.cpp Exception.cpp)

add_library(Print SHARED GeneralPrint.cpp PrintMatrixFile.cpp)

target_link_libraries(main Matrix Print)