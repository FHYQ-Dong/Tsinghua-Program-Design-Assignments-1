#ifndef _WEB_SOCKET_H
#define _WEB_SOCKET_H
#include <winsock2.h>
#include <Windows.h>

#pragma comment(lib, "ws2_32.lib")

#define WSASETUPERROR -1
#define BINDERROR -2
#define LISTENERROR -3
#define SOCKETCLOSEERROR -4
#define WSACLOSEERROR -5
#define ACCEPTERROR -6
#define OK 0
typedef int SOCKET_STATUS;

extern SOCKET_STATUS webSocketInit(SOCKET *sockSrv, u_short port);

extern SOCKET_STATUS webSocketClose(SOCKET *sockSrv);

extern SOCKET_STATUS webSocketAccept(SOCKET *sockSrv, SOCKET *sockConn);

#endif // !_WEB_SOCKET_H