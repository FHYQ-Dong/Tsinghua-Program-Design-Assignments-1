#include <winsock2.h>
#include <Windows.h>
#include <stdio.h>
#pragma comment(lib, "ws2_32.lib")

#include "web-socket.h"

extern SOCKET_STATUS webSocketInit(SOCKET *sockSrv, u_short port) {
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to load Winsock");
        return WSASETUPERROR;
    }

    //创建用于监听的套接字
    *sockSrv = socket(AF_INET, SOCK_STREAM, 0);

    SOCKADDR_IN addrSrv;
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(port); //1024以上的端口号
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

    int retVal = bind(*sockSrv, (LPSOCKADDR)&addrSrv, sizeof(SOCKADDR_IN));
    if (retVal == SOCKET_ERROR){
        printf("Failed bind: %d\n", WSAGetLastError());
        return BINDERROR;
    }

    if (listen(*sockSrv, 5) == SOCKET_ERROR){
        printf("Listen failed: %d\n", WSAGetLastError());
        return LISTENERROR;
    }
    return OK;
}

extern SOCKET_STATUS webSocketClose(SOCKET *sockSrv) {
    if (closesocket(*sockSrv) != 0) return SOCKETCLOSEERROR;
    free(sockSrv);
    if (WSACleanup() != 0) return WSACLOSEERROR;
}

extern SOCKET_STATUS webSocketAccept(SOCKET *sockSrv, SOCKET *sockConn) {
    SOCKADDR_IN addrClient;
    int len = sizeof(SOCKADDR);
    *sockConn = accept(*sockSrv, (SOCKADDR*)&addrClient, &len);
    if (*sockConn == INVALID_SOCKET) {
        printf("Accept failed: %d\n", WSAGetLastError());
        return ACCEPTERROR;
    }
    return OK;
}