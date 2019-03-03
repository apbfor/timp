cmake_minimum_required(VERSION 3.13)
project(test_empty)

set(CMAKE_CXX_STANDARD 17)

add_executable(example example/example_test.cpp example/example.cpp example/example.h)

add_executable(example_main example/main.cpp example/example.cpp example/example.h)

add_executable(2.1_main task2-1/task2-1_main.cpp task2-1/task2-1.cpp task2-1/task2-1.h)

add_executable(2.1_test task2-1/task2-1_test.cpp task2-1/task2-1.cpp task2-1/task2-1.h)

add_executable(2.2_main task2-2/task2-2_main.cpp task2-2/task2-2.cpp task2-2/task2-2.h)

add_executable(2.2_test task2-2/task2-2_test.cpp task2-2/task2-2.cpp task2-2/task2-2.h)