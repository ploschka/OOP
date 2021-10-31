g++ -c main.cpp Matrix.cpp Exception.cpp GeneralPrint.cpp PrintMatrixConsole.cpp
g++ -static *.o -o main

mv *.o Static2/
mv main Static2/
