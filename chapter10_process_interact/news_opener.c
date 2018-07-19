//
// Created by admin on 2018/7/18.
//

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void error(const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

//这里都是虚拟的函数，这两个方法在windows上没有
int pipe(int filedes[2]) {
    return 0;
}

int fork() {
    return 0;
}

void open_url(char *url) {
    char launch[255];
    //在windows上打开网页
    sprintf(launch, "cmd /c start %s", url);
    system(launch);
    //在linux上打开网页
    sprintf(launch, "x-www-browser '%s' &", url);
    system(launch);
    //在Mac上打开网页
    sprintf(launch, "open '%s'", url);
    system(launch);
}

int main(int argc, char *argv[]) {
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=http://jjr18.com", NULL};
    int fd[2];
    if (pipe(fd) == -1) {
        error("Can't create the pipe");
    }
    pid_t pid = fork();
    if (pid == -1) {
        error("Can't fork process");
    }
    if (!pid) {//进入子进程
        dup2(fd[1], 1);//把标准输出指向管道的输入端
        close(fd[0]);//子进程不会读取管道，所以将子进程的管道输入端关闭
        if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phrase, NULL, vars) == -1) {
            error("Can't run script");
        }
    }
    //主进程
    dup2(fd[0], 0);//把标准输入指向管道的读取端
    close(fd[1]);//主进程不会通过管道输出，所以关闭管道输出端

    char line[255];
    while (fgets(line, 255, stdin)) {//这里也可以用fd[0]
        if (line[0] == '\t')
            open_url(line + 1);
    }

    return 0;
}
