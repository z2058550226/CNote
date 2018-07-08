//
// Created by admin on 2018/7/7.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct island {
    const char *name;
    const char *opens;
    const char *closes;
    struct island *next;
} island;

void display(island *start) {
    island *i = start;
    while (i) {
        printf("Name: %s\n open: %s-%s\n", i->name, i->opens, i->closes);
        i = i->next;
    }
}

int main(int argc, char *argv[]) {

    island amity = {"Amity", "09:00", "17:00", NULL};
    island craggy = {"Craggy", "09:00", "17:00", NULL};
    island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
    island shutter = {"Shutter", "09:00", "17:00", NULL};

    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;

    display(&amity);

    island *p = malloc(sizeof(island));

    return 0;
}
