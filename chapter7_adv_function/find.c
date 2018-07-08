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

void find() {
    int i;
    puts("Search results:");
    puts("-------------------------");
    for (i = 0; i < NUM_ADS; ++i) {
        if (strstr(ADS[i], "sports") && !strstr(ADS[i], "bieber")) {
            printf("%s\n", ADS[i]);
        }
    }
    puts("-------------------------");
}

int main(int argc, char *argv[]) {
    //这里虽然能够正确运行，但如果需求改变，要求更复杂的搜索逻辑不能总是复制函数。
    //这时就需要更高级的东西——把代码传给函数。
    find();

    return 0;
}