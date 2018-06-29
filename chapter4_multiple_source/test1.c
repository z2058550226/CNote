//
// Created by admin on 2018/6/29.
//

#include <stdio.h>
#include <limits.h>
#include <float.h>

//打印当前计算机各种数据类型最大值和最小值，与占用空间
int main() {
    printf("The value of INT_MAX is %i\n", INT_MAX);
    printf("The value of INT_MIN is %i\n", INT_MIN);
    printf("An int takes %i bytes\n", sizeof(int));

    printf("The value of FLT_MAX is %f\n", FLT_MAX);
    printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
    printf("A float takes %i bytes\n", sizeof(float));
}