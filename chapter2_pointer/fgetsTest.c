//
// Created by admin on 2018/6/28.
//

#include <stdio.h>

int main() {
    char food[5];
    printf("Enter your food:");
    //第一个参数为字符串指针，第二个参数接收字符串长度(包括了'\0',所以这里最长有4个字符)，第三个参数是输入来源
    //stdin表示输入来源是键盘
    fgets(food, sizeof(food), stdin);
    printf("your food is : %s\n", food);
    food = "aaaa";
    return 0;
}