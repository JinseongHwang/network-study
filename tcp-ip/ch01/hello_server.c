//
// Created by jinseonghwang on 21. 3. 9..
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int serv_sock;
    int clnt_sock;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    char message[] = "Hello World!";

    if (argc != 2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    // socket 생성: serv_sock에는 숫자가 저장된다. (파일 디스크립터 또는 소켓 핸들이라고 부름)
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("socket() error");

    // IP와 PORT를 초기화하는 과정 (아래 4줄)
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    // IP와 PORT를 할당
    if (bind(serv_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");

    // 접속 가능한 상태로 만듦
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    // 요청 수락
    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr *) &clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1)
        error_handling("accept() error");

    write(clnt_sock, message, sizeof(message));
    close(clnt_sock); // 소켓 데이터 반환
    close(serv_sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}