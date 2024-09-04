#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Author:Yusi 2022102330
// Time:2024/4/19

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(int sockfd)
{
    char buff[MAX];
    int n;
    for (;;) {
        bzero(buff, MAX);

        //read the data from client
        read(sockfd, buff, sizeof(buff));
        printf("From client: %s", buff);
        

        // exit the loop if receiver "exit" message
        if (strncmp(buff, "exit", 4) == 0) {
            printf("Server Exit...\n");
            write(sockfd, buff, sizeof(buff));
            break;
        }
     
        else if (strncmp(buff, "hi", 2) == 0) {
            strcpy(buff, "Hello\n");
        }
        else if (strncmp(buff, "Who are u, sir???",12) == 0) {
            strcpy(buff, "I'm your OS Teacher He!!!!\n");
        }
        else if (strncmp(buff, "Omg!!I did not recognize u teacher Bobo!!",40) == 0) {
            strcpy(buff, "Keep my handsome face in your mind, boy!\n");
        }
        printf("\tTo client: %s", buff);


        // Send message to client
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));

    }
}

int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");

    bzero(&servaddr, sizeof(servaddr));

    // assign IP and Port
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Bind socket
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Listen
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);

    // Accept client
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server acccept failed...\n");
        exit(0);
    }
    else
        printf("server acccept the client...\n");

    func(connfd);

    close(sockfd);
}
