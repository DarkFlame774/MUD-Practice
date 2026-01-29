#include <iostream>
#include "network.h"

int main()
{
    StartSocketLib;
    int err;
    socket_t sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == SOCKET_INVALID) {
        std::cout << GetSocketError;
        return -1;
    }
    std::cout << "sockets created successfully\n";
    sockaddr_in socketAddress;
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(2000);
    socketAddress.sin_addr.S_un.S_addr = inet_addr("172.17.25.219");
    memset(&socketAddress.sin_zero, 0, sizeof(socketAddress.sin_zero));

    err = connect(sock, (const sockaddr*)&socketAddress, sizeof(socketAddress));
    if (checkError(err)) return -1;
    std::cout << "connection established\n";
    const char data[128] = "hello form sender side";
    int go = 0;
    std::cin >> go;
    int sent;
    if (go) { sent = send(sock, (const char*)&data, 128, 0); }
    std::cout << "Total data sent is " << sent << "\n";
    std::cin >> go;
}
