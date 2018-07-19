//
// Created by admin on 2018/7/18.
//

#include <stdio.h>
#include <io.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    dup2(4,3);
    exit(0);
}