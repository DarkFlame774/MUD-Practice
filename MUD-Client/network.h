#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#ifdef _WIN32
#pragma comment(lib, "Ws2_32.lib")
#include "WinSock2.h"
#include "WS2tcpip.h"
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#endif

#ifdef _WIN32
WSADATA g_wsadata;
#define CloseSocket closesocket
#define GetSocketError WSAGetLastError
#define StartSocketLib WSAStartup(MAKEWORD(2,2),&g_wsadata);
#define CloseSocketLib WSACleanup();
typedef SOCKET socket_t;
#define SOCKET_INVALID INVALID_SOCKET
#else
typedef int socket_t;
#define SOCKET_INVALID (-1)
#define CloseSocket close
#define GetSocketError errno
#define StartSocketLib {}
#define CloseSocketLib {}
#endif

bool checkError(int err) {
	if (err < 0) {
		std::cout << "\nError:" << GetSocketError;
		return true;
	}
	return false;
}