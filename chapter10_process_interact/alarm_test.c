//
// Created by admin on 2018/7/19.
// env: linux
//

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
//闹钟事件回调
void alarm_callback(int sig) {
    printf("alarm callback executed!");
    printf("alarm callback executed!");
    printf("alarm callback executed!");
    printf("alarm callback executed!");
}

//监听系统信号
int catch_signal(int sig, void (*handler)(int)) {
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

int main(int argc, char *argv[]) {
    //监听闹钟事件
    if (catch_signal(SIGALRM, alarm_callback) == -1) {
        fprintf(stderr, "Can't map the handler");
        exit(2);
    }
    alarm(5);//定时5秒后开启定时任务

    char name[30];
    printf("Enter your name:");
    fgets(name, 30, stdin);
    printf("Hello %s\n", name);

    char ageC[5];
    printf("Enter your age:");
    fgets(ageC, 5, stdin);
    int age = strtol(ageC, NULL, 10);//将输入转化成十进制整数，不带入错误信息字符串（第二个NULL参数）
    printf("Your age is %d\n", age);

    return 0;
}