cmake_minimum_required(VERSION 3.10)
project(CNote C)
#指定静态链接库的头文件位置，相当于gcc的-I选项
include_directories(chapter8_shared_code/mylib)
#指定.a文件所在目录，相当于gcc的-L选项
link_directories(chapter8_shared_code/mylib)
#如果想直接使用子目录当一个lib目录，就在子目录中创建一个CMakeList.txt文件
#在主工程中添加lib目录，lib目录可以指定编译出来的是静态链接库还是动态链接库（STATIC/SHARED）
add_subdirectory(chapter8_shared_code/mylib)

set(CMAKE_C_STANDARD 11)

add_executable(CNote chapter8_shared_code/test_code.c)
#将静态链接库与当前项目进行链接，否则编译器找不到(这里的.a文件是使用mylib目录下的CMake指令编译出来的，自己ar的会报错不知道为什么，但后来ar的又好使了)
#这里相当于gcc的-l选项
target_link_libraries(CNote libhfsecurity.a)