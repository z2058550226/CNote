//
// Created by admin on 2018/7/24.
// 最简单的线程实例，MinGW不可用
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

//线程中调用的函数返回值类型为void *
void *does_not(void *a) {
    int i = 0;
    for (i = 0; i < 5; ++i) {
        sleep(1);
        puts("Does not!");
    }
    return NULL;//没有什么可以返回的就返回NULL
}

void *does_too(void *a) {
    int i = 0;
    for (i = 0; i < 5; ++i) {
        sleep(1);
        puts("Does too!");
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t t0;
    pthread_t t1;
    if (pthread_create(&t0, NULL, does_not, NULL) == -1)
        error("can't create thread t0");
    if (pthread_create(&t1, NULL, does_too, NULL) == -1)
        error("can't create thread t1");
    puts("waiting for the thread");
    void *result;
    puts("result var has declared");
    if (pthread_join(t0, &result) == -1)
        error("can't recycle thread t0");
    puts("thread t0 joined");
    if (pthread_join(t1, &result) == -1)
        error("can't recycle thread t1");
    puts("thread t1 joined");
    return 0;
}
