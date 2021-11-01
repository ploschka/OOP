message("MODE=${MODE}")

add_library(Print${MODE} SHARED PrintMatrix${MODE}.cpp GeneralPrint.cpp)

add_library(Matrix SHARED Matrix.cpp Exception.cpp)

add_executable(main main.cpp)

target_link_libraries(Matrix Print${MODE})

target_link_libraries(main Matrix)