//
// Created by admin on 2018/6/27.
//
#include <stdio.h>
#include <string.h>

void fun(char msg[]) {
    printf("message is %s\n", msg);//message is cookies make you fat
    printf("message occupies %i bytes\n", sizeof(msg));//message occupies 4 bytes
    printf("%d\n",strlen(msg));
}

int main() {

    char msg[] ="cookies make you fat";

    fun(msg);

    printf("%d\n", sizeof(int));//4

    return 0;
}