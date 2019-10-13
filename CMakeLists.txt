cmake_minimum_required(VERSION 3.12)
project(task2 C)


##Compiling and linking tuple_t;thus, per task 2 a specifictions



set(CMAKE_C_STANDARD 99 tuple_t.c)
add_library(tupleA SHARED tuple_t.c)

add_executable(task2a tupleDriver.c tuple_t.h)
target_link_libraries(task2a tupleA)



##Compiling and linking tuple_t;thus, per task 2 b specifictions


set(CMAKE_C_STANDARD 99 tupleExtented.c)
add_library(tupleB SHARED tupleExtented.c)

add_executable(task2B tupleExtendedDriver.c tupleExtented.h)
target_link_libraries(task2B tupleB)



