#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

int evaluateExpression(const char *expression)
{
    int num1, num2;
    char operator;
    sscanf(expression, "%d%c%d", &num1, &operator, & num2);

    switch (operator)
    {
    case '+':
        return num1 + num2;
    default:
        printf("Unsupported operator: %c\n", operator);
        return 0;
    }
}

int add(const char *data)
{
    int result = evaluateExpression(data);
    // printf("Result: %d\n", result);
    return result;
}

void *clientHandler(void *clientSocketPtr)
{
    int client_socket = *((int *)clientSocketPtr);
    char buffer[1024];

    while (1)
    {
        ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received == -1)
        {
            perror("Receive error");
            break;
        }

        if (bytes_received == 0 || strcmp(buffer, "exit") == 0)
        {
            break;
        }

        printf("Received data: %.*s\n", (int)bytes_received, buffer);

        int ans = add(buffer);
        printf("Answer: %d\n", ans);

        char ansStr[20];
        snprintf(ansStr, sizeof(ansStr), " Answer: %d", ans);
        strcat(buffer, ansStr);

        send(client_socket, buffer, strlen(buffer), 0);
    }

    close(client_socket);
    return NULL;
}

int main()
{
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        perror("Socket creation error");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Binding error");
        return 1;
    }

    if (listen(server_socket, 5) == -1)
    {
        perror("Listening error");
        return 1;
    }

    printf("Server listening on port 8080...\n");

    while (1)
    {
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket == -1)
        {
            perror("Accept error");
            return 1;
        }

        printf("Connected by %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pthread_t thread;
        if (pthread_create(&thread, NULL, clientHandler, &client_socket) != 0)
        {
            perror("Thread creation error");
            return 1;
        }

        pthread_detach(thread);
    }

    close(server_socket);

    return 0;
}

/*
gcc server.c -o server -Wall
 */

/* 
Name: Rohit Saini
Erp: 1032200897
Panel: C
RollNo: PC-41 */