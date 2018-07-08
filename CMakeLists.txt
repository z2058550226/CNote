cmake_minimum_required(VERSION 3.10)
project(CNote C)

set(CMAKE_C_STANDARD 11)

set(APP_NAME CNote)

add_executable(${APP_NAME} chapter6_data_struct/linked_list.c)

add_library(MyLib lib/text_lib.c)