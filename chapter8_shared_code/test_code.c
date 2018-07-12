//
// Created by admin on 2018/7/11.
//

#include <stdio.h>
#include "encrypt.h"
#include "checksum.h"

int main(int argc, char *argv[]) {
    char s[] = "Speak friend and enter";

    encrypt(s);

    printf("Encrypt to %s\n", s);

    printf("Checksum is %i\n", checksum(s));

    encrypt(s);

    printf("Decrypt back to %s\n", s);

    printf("Checksum is %i\n", checksum(s));

    return 0;
}