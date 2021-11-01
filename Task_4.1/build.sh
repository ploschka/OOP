case "$1" in
-f) Mode="File";;
-c) Mode="Console";;
esac

cmake -S. -B Build -DMODE=${Mode} && cd Build && make