//
// Created by admin on 2018/7/4.
//

#include <stdio.h>

typedef enum {
    COUNT, WEIGHT, VOLUME
} unit_of_amount;

typedef union {
    int count;
    float weight;
    float volume;
} quantity;

typedef struct {
    const char *name;
    const char *country;
    quantity amount;
    unit_of_amount unit;
} fruit_order;

int main(int argc, char *argv[]) {
    //C89表示法
    quantity q1 = {4};
    //指定初始化器（属于C99标准，在C++中不支持，在OC中支持）
    quantity q2 = {.weight = 5};
    //“点”表示法
    quantity q3;
    q3.volume = 3.7f;

    fruit_order order = {"apple", "china", {.weight = 5}, WEIGHT};

    return 0;
}