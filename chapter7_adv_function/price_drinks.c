//
// Created by admin on 2018/7/11.
//


#include <stdio.h>
#include <stdarg.h>

enum drink {
    MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};

double price(enum drink d) {
    switch (d) {
        case MUDSLIDE:
            return 6.79;
        case FUZZY_NAVEL:
            return 5.31;
        case MONKEY_GLAND:
            return 4.82;
        case ZOMBIE:
            return 5.89;
    }
    return 0;
}

double total(int args, ...) {
    double total = 0;
    va_list drinks;
    va_start(drinks, args);
    for (int i = 0; i < args; ++i) {
        total += price(va_arg(drinks, enum drink));
    }
    va_end(drinks);
    return total;
}

int main(int argc, char *argv[]) {
    double t = total(3, MUDSLIDE, FUZZY_NAVEL, ZOMBIE);
    printf("Total = %.2f\n", t);
    printf("Total = %.2f\n", total(1, ZOMBIE));
    printf("Total = %.2f\n", total(4, MUDSLIDE, MUDSLIDE, FUZZY_NAVEL, ZOMBIE));
    return 0;
}
