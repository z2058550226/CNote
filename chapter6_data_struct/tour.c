//
// Created by Administrator on 2018/7/8 0008.
//
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

island *create(const char *name) {
    island *i = malloc(sizeof(island));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void release(island *start) {
    island *i = start;
    island *next = NULL;
    for (; i != NULL; i = next) {
        next = i->next;
        free(i->name);
        free(i);
    }
}

void display(island *start) {
    island *i = start;
    while (i) {
        printf("Name: %s\n open: %s-%s\n", i->name, i->opens, i->closes);
        i = i->next;
    }
}

int main(int argc, char *argv[]) {
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;

    char name[80];
    for (; fgets(name, 80, stdin) != NULL; i = next) {
        next = create(name);
        if (start == NULL) {
            start = next;
        }
        if (i != NULL) {
            i->next = next;
        }
    }

    display(start);

    release(start);

    return 0;
}

