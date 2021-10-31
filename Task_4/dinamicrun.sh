cd DinamicBuild/

case "$1" in
1) mv Console/libPrint.so ./;;
2) mv File/libPrint.so ./;;
esac
./main
case "$1" in
1) mv libPrint.so Console/;;
2) mv libPrint.so File/;;
esac