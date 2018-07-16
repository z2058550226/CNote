//
// Created by admin on 2018/7/16.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    puts("inv.1\n");
    printf("Diners: %s\n", argv[1]);
    puts("inv.2\n");
    printf("Juice: %s\n", getenv("JUICE"));
    char *a = "aaaaa";
    a[3] = 'b';
    puts("inv.3\n");
    printf("Person: %s\n", getenv("PERSON"));
    puts("inv.4\n");
    return 2;
}