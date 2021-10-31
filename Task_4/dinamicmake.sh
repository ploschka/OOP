cd DinamicBuild

mv File/CMakeLists.txt ../
cmake -S .. -B . && make && mv ../CMakeLists.txt ./File && mv libPrint.so File/ && mv Console/CMakeLists.txt ../ && cmake -S .. -B . && make && mv ../CMakeLists.txt ./Console && mv libPrint.so Console/