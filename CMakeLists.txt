cmake_minimum_required(VERSION 3.24)
project(FFT_tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ltbb -lpthread -pthread -O0")

include_directories(.)

add_executable(FFT_tests
        FFT_class.cpp
        FFT_class.h
        log_duration.h
        main.cpp
        support.h
        test_FFT_class.h
        FFT_recursive.h
        FFT_recursive.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE tbb)
