//
// Created by admin on 2018/6/28.
//

#include <stdio.h>

void subStrPrint(char *oriStr, int beginIndex) {
    printf("%s\n", oriStr + beginIndex);
}

int main() {
    char *s = "hello world";
    subStrPrint(s,6);//world
    return 0;
}
