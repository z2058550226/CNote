//
// Created by admin on 2018/7/11.
//

#include "encrypt.h"

void encrypt(char *message) {
    while (*message) {
        *message = (char) (*message ^ 31);
        message++;
    }
}