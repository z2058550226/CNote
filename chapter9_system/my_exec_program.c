//
// Created by admin on 2018/7/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    puts("ori.1\n");
    char *my_env[] = {"JUICE=peach and apple", "PERSON=MaChao and QinHao", NULL};
    puts("ori.2\n");
    execle("dinner_info", "dinner_info", "4", NULL, my_env);
    puts("ori.3\n");
    FILE *file = fopen("errLog.txt", "w");
    fprintf(file, "err output! %s\n", "aaa");
    puts("ori.4\n");
    fprintf(file, "err output! %s\n", "bbb");
    puts("ori.5\n");
    fprintf(file, "err output! %s\n", "ccc");
    puts("ori.6\n");
    fclose(file);
    return 1;
}