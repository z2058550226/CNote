//
// Created by admin on 2018/7/20.
// linux
//

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

//windows 导包
//#include <winsock2.h>

//linux 导包
#include <sys/socket.h>
#include <arpa/inet.h>

void error(const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int read_in(int socket, char *buf, int len) {
    char *s = buf;
    int slen = len;
    int c = recv(socket, s, slen, 0);
    while ((c > 0) && (s[c - 1] != '\n')) {
        s += c;
        slen -= c;
        c = recv(socket, s, slen, 0);
    }
    if (c < 0)
        return c;
    else if (c == 0)
        buf[0] = '\0';
    else
        s[c - 1] = '\0';
    return len - slen;
}

int main(int argc, char *argv[]) {

    char *advice[] = {
            "Take smaller bites\r\n",
            "Go for the tight jeans. No they do NOT make you look fat.\r\n",
            "One word: inappropriate\r\n",
            "Just for today, be honest. Tell your boss what you *really* think\r\n",
            "You might want to rethink that haircut\r\n"
    };
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    if (listener_d == -1) {
        error("can't open the socket");
    }

    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t) htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    int c = bind(listener_d, (struct sockaddr *) &name, sizeof(name));
    if (c == -1) {
        error("can't bind the port");
    }

    if (listen(listener_d, 10) == -1) {
        error("can't listen");
    };
    puts("Waiting for connection");

    while (1) {
        struct sockaddr_storage client_addr;

        unsigned int address_size = sizeof(client_addr);
        int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &address_size);
        if (connect_d == -1) {
            error("can't create secondary socket");
        }
        char *msg = advice[rand() % 5];

        int send_result = send(connect_d, msg, strlen(msg), 0);
        if (send_result == -1) {
            error("can't send message to client");
        }
        close(connect_d);
    }
    return 0;
}