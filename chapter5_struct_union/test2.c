//
// Created by admin on 2018/7/3.
//

#include <stdio.h>

typedef struct cell_phone {
    int cell_no;
    const char *wallpaper;
    float minutes_of_charges;
} phone;

int main(int argc, char *argv[]) {
    phone p = {555789, "sinatra.png", 1.35f};
    printf(p.wallpaper);
    return 0;
}