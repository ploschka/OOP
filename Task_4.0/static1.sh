cd Static1
mv CMakeLists.txt ../
cmake -S .. -B . && make && mv ../CMakeLists.txt ./
