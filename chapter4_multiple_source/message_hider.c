//
// Created by admin on 2018/7/2.
//

#include <stdio.h>
#include "encrypt.h"

int main(int argc, char *argv[]) {

    char msg[80];
    while (fgets(msg, 80, stdin)) {
        encrypt(msg);
        printf("%s", msg);
    }

    return 0;
}

void encrypt(char *message) {
    while (*message) {
        *message = (char) (*message ^ 31);
        message++;
    }
}
