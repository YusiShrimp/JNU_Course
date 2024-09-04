#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Author: Yusi 2022102330
// Date: 2024/4/19

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(int sockfd) {
    char buff[MAX];
    int n;
    for (;;) {
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From client: %s", buff);
        if (strncmp(buff, "exit", 4) == 0) {
            printf("Server Exit...\n");
            write(sockfd, buff, sizeof(buff));
            break;
        }

        write(sockfd, buff, sizeof(buff));
    }
}

int main() {
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);

    for (;;) {
        // Accept the data packet from client and verification
        connfd = accept(sockfd, (SA*)&cli, &len);
        if (connfd < 0) {
            printf("server accept failed...\n");
            exit(0);
        }
        else
            printf("server accept the client...\n");

        // Forking a child process to handle client
        if (fork() == 0) {
            close(sockfd); // Child process closes listening socket
            func(connfd); // Child process handles the client
            close(connfd); // Child process closes client socket
            exit(0); // Child process exits after handling client
        }
        else {
            close(connfd); // Parent process closes client socket
        }
    }

    // Close the listening socket
    close(sockfd);

    return 0;
}
