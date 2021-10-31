cd Static
mv CMakeLists.txt ../
cmake -S .. -B . && make && mv ../CMakeLists.txt ./