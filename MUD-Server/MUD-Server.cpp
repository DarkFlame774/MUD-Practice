#include <iostream>
#include "network.h"

int main()
{
    StartSocketLib;
    int err;
    socket_t sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (sock == SOCKET_INVALID) {
        std::cout << GetSocketError;
        return -1;     
    }
    std::cout << "socket created successfully\n";
    sockaddr_in socketAddress;
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(2000);
    socketAddress.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    memset(&socketAddress.sin_zero,0,sizeof(socketAddress.sin_zero));

    err = bind(sock,(const sockaddr*)&socketAddress,sizeof(socketAddress));
    if (checkError(err)) return -1;

    err = listen(sock,1);
    if (checkError(err)) return -1;
    socket_t clientSock;
    sockaddr clientSockAdress;
    std::cout << "waiting for connection";
    clientSock = accept(sock,&clientSockAdress,nullptr);
    if(clientSock == SOCKET_INVALID) return -1;
    std::cout << "connection established\n";
    int rec;
    char data[128];
    rec = recv(clientSock,(char*)&data,sizeof(data), 0);
    std::cout << "Data recievd is " << rec;
    std::cout << "Message: " << data;
    std::cin.get();

}


