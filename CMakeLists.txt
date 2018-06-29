cmake_minimum_required(VERSION 3.10)
project(CNote C)

set(CMAKE_C_STANDARD 11)

add_executable(CNote chapter3_tool/bermuda.c chapter3_tool/order_pizza.c)