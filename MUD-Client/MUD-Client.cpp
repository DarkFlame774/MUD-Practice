#include <iostream>
#include "network.h"

int Main()
{
    StartSocketLib;
    int err;
    socket_t sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == SOCKET_INVALID) {
        std::cout << GetSocketError;
        return -1;
    }
    std::cout << "socket created successfully\n";
    sockaddr_in socketAddress;
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(2000);
    char address[15];
    std::cout << "Enter the IP Address: ";
    std::cin.getline((char*)&address,15);
    socketAddress.sin_addr.S_un.S_addr = inet_addr(address);
    memset(&socketAddress.sin_zero, 0, sizeof(socketAddress.sin_zero));

    err = connect(sock, (const sockaddr*)&socketAddress, sizeof(socketAddress));
    if (checkError(err)) return -1;
    std::cout << "connection established\n";
    bool done = false;
    char data[128];
    while (!done) {
        std::cout << "Enter the Message: ";
        std::cin.getline((char*)&data,128);
        if (strcmp(data, "exit") == 0 || strcmp(data, "servquit") == 0) {
            done = true;
        }
        else {
            int sent;
            sent = send(sock, (const char*)&data,strlen(data) + 1, 0);
            std::cout << "Total data sent is " << sent << "\n";
        }
    }

    
	shutdown(sock, SD_BOTH);
	closesocket(sock);
	CloseSocketLib;
    return 0;
}
