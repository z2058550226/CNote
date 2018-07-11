//
// Created by admin on 2018/7/8.
//

#include <stdio.h>
#include <string.h>

int NUM_ADS = 7;

char *ADS[] = {
        "William: SBM GSOH likes sports, TV, dinging",
        "Matt: SWM NS likes art, movies, theater",
        "Luis: SLM ND likes books, theater, art",
        "Mike: DWM DS likes trucks, sports and bieber",
        "Peter: SAM likes chess, working out and art",
        "Josh: SJM likes sports, movies and theater",
        "Jed: DBM likes theater, books and dinging"
};

int sports_no_bieber(char *s) {
    return strstr(s, "sports") && !strstr(s, "bieber");
}

int sports_or_workout(char *s) {
    return strstr(s, "sports") || strstr(s, "working out");
}

//不抽烟并喜欢戏剧
int ns_theater(char *s) {
    return strstr(s, "NS") && strstr(s, "theater");
}

//艺术戏剧或美食
int arts_theater_or_dinging(char *s) {
    return strstr(s, "art") || strstr(s, "theater") || strstr(s, "dinging");
}

//使用函数指针，动态改变匹配规则
void find(int (*match)(char *)) {
    int i;
    puts("Search results:");
    puts("-------------------------");
    for (i = 0; i < NUM_ADS; ++i) {
        if (match(ADS[i])) {
            printf("%s\n", ADS[i]);
        }
    }
    puts("-------------------------");
}

int main(int argc, char *argv[]) {

    find(arts_theater_or_dinging);
    find(ns_theater);
    find(sports_or_workout);
    find(sports_no_bieber);

    return 0;
}