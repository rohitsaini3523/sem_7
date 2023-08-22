#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[1024];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        perror("Socket creation error");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Connection error");
        return 1;
    }

    printf("Connected to server.\n");

    while (1)
    {
        printf("Enter a message ('exit' to quit): ");
        fgets(buffer, sizeof(buffer), stdin);

        // Remove trailing newline
        buffer[strlen(buffer) - 1] = '\0';

        if (send(client_socket, buffer, strlen(buffer), 0) == -1)
        {
            perror("Send error");
            break;
        }

        if (strcmp(buffer, "exit") == 0)
        {
            break;
        }

        ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received == -1)
        {
            perror("Receive error");
            break;
        }

        printf("Server response: %.*s\n", (int)bytes_received, buffer);
    }
    close(client_socket);
    return 0;
}

/*
gcc client.c -o client -Wall
 */