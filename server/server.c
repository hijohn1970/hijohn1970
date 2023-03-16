#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

void *connection_handler(void *);

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, *new_sock;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    pthread_t threads[MAX_CONNECTIONS];

    // 创建TCP套接字
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 绑定IP地址和端口
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // 监听连接
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // 接受客户端连接
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        printf("New connection accepted\n");

        new_sock = malloc(sizeof *new_sock);
        *new_sock = new_socket;

    printf("有人来连接...");
        // 创建新线程来处理客户端连接
        if (pthread_create(&threads[MAX_CONNECTIONS], NULL, connection_handler, (void*) new_sock) < 0) {
            perror("could not create thread");
            exit(EXIT_FAILURE);
        }
    }

    if (new_socket < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void *connection_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    int read_size;
    char buffer[1024] = {0};

    while ((read_size = recv(sock, buffer, 1024, 0)) > 0) {
        printf("Client message: %s\n", buffer);
        send(sock, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof buffer);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    close(sock);
    free(socket_desc);

    return NULL;
}