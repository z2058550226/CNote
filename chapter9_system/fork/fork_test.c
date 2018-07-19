//
// Created by admin on 2018/7/17.
//

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char *extra[2];
    extra[1]=NULL;
    for (int i = 0; i < 5; ++i)
    {
        pid_t pid = fork();
        printf("pid is: %d\n",pid);
        if (pid==-1)
        {
            fprintf(stderr, "can not fork process: %s\n", strerror(errno));
            return 1;
        }
        if (!pid)// if the pid equals 0 then this process is subprocess.
        {
            puts("suika");
            extra[0] = "EXTRA=test extra";
            if (-1==execle("./printer","./printer","arg1","arg2",NULL,extra))
            {
                fprintf(stderr, "can not execute printer: %s\n", strerror(errno));
                return 1;
            }
        }
    }
    return 0;
}