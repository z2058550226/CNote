//
// Created by admin on 2018/7/16.
//


#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    //先判断是否是linux或者Mac
    if (execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1) {
        if (execlp("ipconfig", "ipconfig", NULL) == -1) {
            fprintf(stderr, "Can't run ipconfig: %s", strerror(errno));
            return 1;
        }
    }
    return 0;
}
