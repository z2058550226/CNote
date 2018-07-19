//
// Created by admin on 2018/7/18.
//

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void error(const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char const *argv[]) {
    char *extra[2];
    extra[1] = NULL;
    for (int i = 0; i < 5; ++i) {
        pid_t pid = fork();
        printf("pid is: %d\n", pid);
        if (pid == -1) {
            error("can not fork process");
        }
        if (!pid)// if the pid equals 0 then this process is subprocess.
        {
            puts("suika");
            extra[0] = "EXTRA=test extra";
            if (-1 == execle("./printer", "./printer", "arg1", "arg2", NULL, extra)) {
                error("can not execute printer");
            }
        }
    }
    return 0;
}