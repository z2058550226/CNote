#include <stdio.h>
#include <stdbool.h>

int a() {
    printf("function a\n");
    return 0;
}

int b() {
    printf("function b\n");
    return 1;
}

int c() {
    printf("function c\n");
    return 1;
}

int main() {

    if (a() || b() || c()) {
        printf("true\n");
    }

    if (a() && b() && c()) {
        printf("true\n");
    }

    for (int i = 0; i < 10; ++i) {
        printf("%p\n",&i);
    }


    return 0;
}