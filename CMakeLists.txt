cmake_minimum_required(VERSION 3.13)
project(test_empty)

set(CMAKE_CXX_STANDARD 17)


#example
add_executable(example example/example_test.cpp example/example.cpp example/example.h)
add_executable(example_main example/main.cpp example/example.cpp example/example.h)


#task2-1
add_executable(2.1_main task2-1/task2-1.cpp task2-1/task2-1.h task2-1/main.cpp)
add_executable(2.1_test task2-1/task2-1.cpp task2-1/task2-1.h)


#task2-2
add_executable(2.2_main task2-2/task2-2.cpp task2-2/task2-2.h)
add_executable(2.2_test task2-2/task2-2.cpp task2-2/task2-2.h)

# task2-3
add_executable(task2-3_test task2-3/task2-3.cpp task2-3/tests.cpp)
add_executable(task2-3_main task2-3/task2-3.cpp task2-3/main.cpp)

# task2-4
add_executable(task2-4_test task2-4/task2-4.cpp task2-4/tests.cpp)
add_executable(task2-4_main task2-4/task2-4.cpp task2-4/main.cpp)

#task2-5
add_executable(task2-5_test task2-5/task2-5.cpp task2-5/tests.cpp)
add_executable(task2-5_main task2-5/task2-5.cpp task2-5/main.cpp)

#task2-6
add_executable(task2-6_test task2-6/task2-6.cpp task2-6/tests.cpp)
add_executable(task2-6_main task2-6/task2-6.cpp task2-6/main.cpp)

#ddz
add_executable(ddz_test DDZ/RKMatcher.cpp DDZ/ddz-test.cpp DDZ/RKMatcher.h)
add_executable(ddz_main DDZ/RKMatcher.cpp DDZ/ddz-main.cpp DDZ/RKMatcher.h)