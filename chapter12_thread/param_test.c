//
// Created by admin on 2018/7/24.
// 线程函数的参数和返回值
//

#include <stdio.h>
#include <pthread.h>

void *do_stuff(void *param) {//线程函数可以接收一个void指针参数
    long thread_no = (long) param;//把它转回long
    printf("Thread number %ld\n", thread_no);
    return (void *) (thread_no + 1);
}

int main(int argc, char *argv[]) {
    pthread_t threads[3];
    long t;
    for (t = 0; t < 3; ++t) {
        //将long型变量t的值转化为void指针类型。即线程函数的实参
        pthread_create(&threads[t], NULL, do_stuff, (void *) t);
    }
    void *result;
    for (t = 0; t < 3; ++t) {
        //将线程的返回值传给result。
        pthread_join(threads[t], &result);
        printf("Thread %ld returned %ld\n", t, (long) result);
    }
    return 0;
}

