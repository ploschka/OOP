set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE Threads::Threads)