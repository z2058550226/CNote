//
// Created by admin on 2018/6/28.
//
#include <stdio.h>

int main() {
    char first_name[20];
    char last_name[20];
    printf("please input your name: ");
    scanf("%19s %19s", first_name, last_name);//读取两个字符，中间用空格分开，输入：suika jy
    printf("your input is FirstName: %s, LastName: %s ", first_name, last_name);//输出：your input is FirstName: suika, LastName: jy
    return 0;
}
