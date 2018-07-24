//
// Created by admin on 2018/7/24.
// 线程安全问题的解决
//

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;

int beers = 2000000;//一开始有200万瓶啤酒

void *drink_lots(void *a) {
    int i;
    for (i = 0; i < 100000; ++i) {
        pthread_mutex_lock(&beers_lock);
        beers = beers - 1;
        pthread_mutex_unlock(&beers_lock);
    }
    printf("beers = %i\n", beers);
    return NULL;
}

void *drink_lots2(void *a) {
    int i;
    pthread_mutex_lock(&beers_lock);
    for (i = 0; i < 100000; ++i) {
        beers = beers - 1;
    }
    pthread_mutex_unlock(&beers_lock);
    printf("beers = %i\n", beers);
    return NULL;
}

int main(int argc, char *argv[]) {

    pthread_t threads[20];
    int t;
    printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers, beers);
    for (t = 0; t < 20; ++t) {
        pthread_create(&threads[t], NULL, drink_lots2, NULL);
    }
    void *result;
    for (t = 0; t < 20; ++t) {
        pthread_join(threads[t], &result);
    }

    printf("There are now %i bottles of beer on the wall\n", beers);

    return 0;
}
