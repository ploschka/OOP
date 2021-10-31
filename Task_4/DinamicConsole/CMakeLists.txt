add_executable(main main.cpp)

add_library(Matrix SHARED Matrix.cpp Exception.cpp)

add_library(PrintMatrix SHARED GeneralPrint.cpp PrintMatrixConsole.cpp)

target_link_libraries(main Matrix PrintMatrix)