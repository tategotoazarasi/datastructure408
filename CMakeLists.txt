cmake_minimum_required(VERSION 3.28)
project(datastructure408 C)

set(CMAKE_C_STANDARD 23)

find_package(Check REQUIRED)

add_executable(datastructure408 main.c
        global.h
        list/list.h
        list/sqlist/sqlist.h
        list/sqlist/sqlist.c
        list/sqlist/sqlist_test.h
        list/sqlist/sqlist_test.c
        list/sqlist/sqlist_problems.h
        list/sqlist/sqlist_problems.c)

# 链接Check库到测试可执行文件
target_link_libraries(datastructure408 ${CHECK_LIBRARY})

# 包含头文件目录
target_include_directories(datastructure408 PRIVATE ${CHECK_INCLUDE_DIRS})
