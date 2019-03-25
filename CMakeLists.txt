cmake_minimum_required(VERSION 3.13)
project(test_empty)

set(CMAKE_CXX_STANDARD 17)


#example
add_executable(example example/example_test.cpp example/example.cpp example/example.h)
add_executable(example_main example/main.cpp example/example.cpp example/example.h)


#task2-1
add_executable(2.1_main task2-1/task2-1_main.cpp task2-1/task2-1.cpp task2-1/task2-1.h)
add_executable(2.1_test task2-1/task2-1_test.cpp task2-1/task2-1.cpp task2-1/task2-1.h)


#task2-2
add_executable(2.2_main task2-2/task2-2_main.cpp task2-2/task2-2.cpp task2-2/task2-2.h)
add_executable(2.2_test task2-2/task2-2_test.cpp task2-2/task2-2.cpp task2-2/task2-2.h)

# task2-3
add_executable(task2-3_test task2-3/task2-3.cpp task2-3/task2-3_test.cpp)
add_executable(task2-3_main task2-3/task2-3.cpp task2-3/task2-3_main.cpp)

# task2-4
add_executable(task2-4_test task2-4/task2-4.cpp task2-4/task2-4_test.cpp)
add_executable(task2-4_main task2-4/task2-4.cpp task2-4/task2-4_main.cpp)