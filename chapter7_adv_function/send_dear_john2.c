//
// Created by admin on 2018/7/11.
//

#include <stdio.h>

enum response_type {
    DUMP, SECOND_CHANCE, MARRIAGE
};

typedef struct {
    char *name;
    enum response_type type;
} response;

void dump(response r) {
    printf("Dear %s,\n", r.name);
    puts("Unfortunately your last date contact us to");
    puts("say that they will not be seeing you again");
}

void second_chance(response r) {
    printf("Dear %s,\n", r.name);
    puts("Good news:your last date has asked us to");
    puts("arrange another meeting. Please call ASAP");
}

void marriage(response r) {
    printf("Dear %s,\n", r.name);
    puts("Congratulations! Your last date has contacted");
    puts("us with a proposal of marriage");
}

void (*replies[])(response) = {dump, second_chance, marriage};

int main(int argc, char *argv[]) {
    response r[] = {
            {"Mike",    DUMP},
            {"Luis",    SECOND_CHANCE},
            {"Matt",    SECOND_CHANCE},
            {"William", MARRIAGE}
    };
    int i;
    for (i = 0; i < 4; i++) {
        //运用函数指针数组和枚举的顺序等于索引的性质动态调用函数
        replies[r[i].type](r[i]);
    }

    return 0;
}