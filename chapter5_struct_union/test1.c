//
// Created by admin on 2018/7/2.
//
#include <stdio.h>
#include <string.h>



struct preferences {
    const char *food;
    float exercise_hours;
};

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};

void catalog(struct fish f) {

}

void label(struct fish *f) {
    char result[80];
    strcpy(result, f->name);
    printf(strcat(result, "\n\n"));
    f->name = "ddd";
    printf(f->name);
    printf("teeth num is%i\n", f->teeth);
}

int main(int argc, char *argv[]) {

    struct fish snappy = {"Snappy", "Piranha", 69, 4, {"Meat", 7.5}};
//    catalog(snappy);
    printf("snappy like eat %s\n",snappy.care.food);
    label(&snappy);
    return 0;
}
