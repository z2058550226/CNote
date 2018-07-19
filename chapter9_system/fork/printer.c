//
// Created by admin on 2018/7/17.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("%s\n", "printer start ----");
    char *extra = getenv("EXTRA");
    printf("Extra: %s\n", extra);
    for (int i = 0; i < argc; ++i)
    {
        printf("No.%i argument is %s\n",i,argv[i] );
    }
    printf("%s\n", "printer end ----");
    return 0;
}