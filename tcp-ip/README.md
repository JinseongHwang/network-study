# TCP/IP 내용 정리

### 연결 요청을 허용하는 소켓의 생성 과정 - server

1. 소켓의 생성 - socket()
2. IP와 PORT번호의 할당 - bind()
3. 연결 요청 가능 상태로 변경 - listen()
4. 연결 요청에 대한 수락 - accept()

### 연결 요청을 보내는 소켓의 생성 과정 - client

1. 소켓의 생성 - socket()
2. 목표 소켓과 연결 - connect()

*프로그램 컴파일 및 실행(on linux)*
```text
gcc hello_server.c -o hserver // 컴파일 및 hserver(named) 프로그램 생성
./hserver 9190 // 9190 포트에서 hserver 프로그램 실행(요청 대기)

gcc hello_client -o hclient // 컴파일 및 hclient 프로그램 생성
./hclient 127.0.0.1 9190 // localhost의 9190 포트에 요청 전송
```