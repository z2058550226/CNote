#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SOUR, SWEET, BITTER, HOT, SALTY
} flavor;

typedef struct food {
    const char *name;
    flavor flv;
    struct food *next;
} food;

void display(food *disFood) {
    while (disFood) {
        printf("The food's name is %s, and the flavor is %i\n", disFood->name, disFood->flv);
        disFood = disFood->next;
    }
}

void releaseFood(food *relFood) {
    if (relFood->next) {
        releaseFood(relFood->next);
    }
    free(relFood);
}

int main(int argc, char const *argv[]) {
    food *cookie = malloc(sizeof(food));
    food *fish = malloc(sizeof(food));
    food *rice = malloc(sizeof(food));

    cookie->name = strdup("cookie");
    cookie->flv = SWEET;
    cookie->next = fish;

    fish->name = strdup("fish");
    fish->flv = SALTY;
    fish->next = rice;

    rice->name = strdup("rice");
    rice->flv = SWEET;
    rice->next = NULL;

    display(cookie);

    releaseFood(cookie);

    //这里的release方法调用失败了，不知道为何
    if (cookie == NULL) {
        printf("1\n");
    } else {
        free(cookie);
    }
    printf("%i\n", cookie == NULL);
    return 0;
}