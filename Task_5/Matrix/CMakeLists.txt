include_directories(${MATRIX_INCLUDE_DIR})

add_library(Matrix SHARED src/Matrix.cpp src/Exception.cpp)

add_library(Print${MODE} SHARED src/PrintMatrix${MODE}.cpp src/GeneralPrint.cpp)

target_link_libraries(Print${MODE} Matrix)