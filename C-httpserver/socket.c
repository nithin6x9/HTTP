
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024 // Define a buffer size for reading data

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("webserver (socket)");
        return 1;
    }
    printf("socket created successfully\n");

    // Create the address to bind the socket to
    struct sockaddr_in host_addr;
    int host_addrlen = sizeof(host_addr);

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&host_addr, host_addrlen) != 0) {
        perror("webserver (bind)");
        return 1;
    }
    printf("socket successfully bound to address\n");

    if (listen(sockfd, SOMAXCONN) != 0) {
        perror("webserver (listen)");
        return 1;
    }

    printf("Server listening for connections\n");

    for (;;) {
        int newsockfd = accept(sockfd, (struct sockaddr *)&host_addr, (socklen_t *)&host_addrlen);
        if (newsockfd < 0) {
            perror("webserver (accept)");
            continue;
        }
        printf("connection accepted\n");

        char buffer[BUFFER_SIZE];
        int valread = read(newsockfd, buffer, BUFFER_SIZE - 1); // Read data into buffer
        if (valread < 0) {
            perror("webserver (read)");
            continue;
        }

        buffer[valread] = '\0'; // Add null terminator to use buffer as a string
        printf("Received message: %s\n", buffer);

        close(newsockfd);
    }
    return 0;
}

/*
#include<arpa/inet.h>
#include<stdio.h>
#include<errno.h>
#include<sys/socket.h>

int main(){
    //CREATING A SOCKET
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("webserver(socket)");
        return 1;
    }

    printf("socket created successfully");

    struct sockaddr_in host_addr;
    int host_addrlen = sizeof(host_addr);

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd,(struct sockaddr*)&host_addr, host_addrlen) != 0){
        perror("Webserver(bind)");
        return 1;
    }
    printf("Socket succesfully bound to address\n");

    return 0;

    //Create the address to bind the socket too
    

}

*/
/*
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include<unistd.h>

#define PORT 8080

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("webserver (socket)");
        return 1;
    }
    printf("socket created successfully\n");

    // Create the address to bind the socket to
    struct sockaddr_in host_addr;
    int host_addrlen = sizeof(host_addr);

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&host_addr, host_addrlen) != 0) {
        perror("webserver (bind)");
        return 1;
    }
    printf("socket successfully bound to address\n");


    if (listen(sockfd,SOMAXCONN) != 0){
        perror("webserver (listen)");
        return 1;
    }

    printf("Server listening for connections\n");

    for (;;){
        int newsockfd = accept(sockfd,(struct sockaddr *)&host_addr,
                            (socklen_t *)&host_addrlen);
        if(newsockfd <0 ) {
            perror("webserver (accept)");
            continue;
        }
        printf("connection acceptedd\n");
        //close(newsockfd);

        int valread = read(newsockfd, buffer, BUFFER_SIZE);
        if(valread < 0){
            perror("webserver (read)");
            continue;
        }

        close(newsockfd);
    }
    return 0;
}*/