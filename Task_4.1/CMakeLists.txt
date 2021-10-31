message("MODE=${MODE}")

add_library(Print${MODE} SHARED PrintMatrix${MODE}.cpp GeneralPrint.cpp)

add_executable(Matrix main.cpp Matrix.cpp Exception.cpp)

target_link_libraries(Matrix Print${MODE})