cd DinamicBuild/

case "$1" in
-c) mv Console/libPrint.so ./;;
-f) mv File/libPrint.so ./;;
esac
./main
case "$1" in
-c) mv libPrint.so Console/;;
-f) mv libPrint.so File/;;
esac