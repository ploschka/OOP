g++ -c main.cpp Matrix.cpp Exception.cpp
g++ -static main.o Matrix.o Exception.o -o main

mv *.o Static2/
mv main Static2/