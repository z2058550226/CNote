//
// Created by admin on 2018/7/18.
// 信号处理器测试程序
// 运行环境：linux
//

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void diediedie(int sig) {
    //这里使用标准输出输出了一段话，在真实项目中不要这样调用
    //因为有些错误就是标准输出无法使用导致的，出错时操作系统会给程序发送信号，此时再用标准输出就会出错。
    puts("Goodbye cruel world....\n");
    exit(1);
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
    // SIGINT表示我们要捕捉中断信号，并将中断处理函数设置为diediedie()函数
    if (catch_signal(SIGINT, diediedie) == -1) {
        fprintf(stderr, "Can't map the handler");
        exit(2);
    }
    char name[30];
    printf("Enter your name:");
    fgets(name, 30, stdin);
    printf("Hello %s\n", name);
    return 0;
}
