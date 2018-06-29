//
// Created by admin on 2018/6/29.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    char *delivery = "";
    int ticket = 0;
    int count = 0;
    char ch;
    while ((ch = (char) getopt(argc, argv, "d:t")) != EOF) {
        switch (ch) {
            case 'd':
                delivery = optarg;
                break;
            case 't':
                ticket = 1;
                break;
            default:
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
        }
    }
    argc -= optind;
    argv += optind;
    if (ticket) {
        puts("Thick crust.");
    }

    if (delivery[0]) {
        printf("To be delivered %s.\n", delivery);
    }

    puts("Ingredients:");

    for (count= 0; count < argc; ++count) {
        puts(argv[count]);
    }
    
    return 0;
}
