//
// Created by admin on 2018/6/28.
//
#include <string.h>
#include <stdio.h>

const char *names_for_dog[] = {"Bowser", "Bonza", "Snodgrass"};

int main() {
    const char *dog = names_for_dog[2];
    printf("%s\n", strstr(dog, "gra"));
    return 0;
}
