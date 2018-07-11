//
// Created by admin on 2018/7/11.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scores[] = {543, 323, 32, 554, 11, 3, 112};

//升序排列数组
int compare_scores(const void *score_a, const void *score_b) {
    int a = *(int *) score_a;
    int b = *(int *) score_b;
    return a - b;
}

//降序排列数组
int compare_scores_desc(const void *score_a, const void *score_b) {
    int a = *(int *) score_a;
    int b = *(int *) score_b;
    return b - a;
}

typedef struct {
    int width;
    int height;
} rectangle;

int compare_areas(const void *rect_a, const void *rect_b) {
    rectangle *a = (rectangle *) rect_a;
    rectangle *b = (rectangle *) rect_b;
    return a->height * a->width - b->height * b->width;
}

int compare_areas_desc(const void *rect_a, const void *rect_b) {
    rectangle a = *(rectangle *) rect_a;//强转优先级大于取内容（*运算）
    rectangle b = *(rectangle *) rect_b;
    return b.height * b.width - a.height * a.width;
}

int compare_names(const void *name_a, const void *name_b) {
    const char *a = *(const char **) name_a;
    const char *b = *(const char **) name_b;
    return strcmp(a, b);
}

int compare_names_desc(const void *name_a, const void *name_b) {
    return -compare_names(name_a, name_b);
}

int main(int argc, char *argv[]) {

    int i;

    qsort(scores, 7, sizeof(int), compare_scores_desc);
    puts("These are the score in order:");
    for (i = 0; i < 7; ++i) {
        printf("Score = %i\n", scores[i]);
    }

    char *names[] = {"Karen", "Mark", "Brett", "Molly"};
    qsort(names, 4, sizeof(char *), compare_names);
    puts("These are the names in order:");
    for (i = 0; i < 4; i++) {
        printf("Name = %s\n", names[i]);
    }

    return 0;
}