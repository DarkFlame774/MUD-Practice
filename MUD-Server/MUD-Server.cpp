#include <iostream>
#include "network.h"
#include <vector>

int main()
{
    StartSocketLib;
    int err;
    std::vector<int> socketList;
    socket_t lsock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (lsock == SOCKET_INVALID) {
        std::cout << GetSocketError;
        return -1;     
    }
  //  std::cout << "Listening socket created successfully\n";
    sockaddr_in socketAddress;
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(2000);
    socketAddress.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    memset(&socketAddress.sin_zero,0,sizeof(socketAddress.sin_zero));
    
    err = bind(lsock,(const sockaddr*)&socketAddress,sizeof(socketAddress));
    if (checkError(err)) return -1;
    
    err = listen(lsock,1);
    if (checkError(err)) return -1;

    fd_set socketSet;
    timeval timezero;
    timezero.tv_sec = 0;
    timezero.tv_usec = 0;
    bool notdone = true;
    sockaddr clientSockAdress;
    std::vector<int>::iterator itr;
    while (notdone) {

            FD_ZERO(&socketSet);
            FD_SET(lsock, &socketSet);
			for (int sock : socketList) {
                FD_SET(sock, &socketSet);
            }
            if (select(0xffffffff, &socketSet, nullptr, nullptr, &timezero)) {
				if (FD_ISSET(lsock, &socketSet)) {
                    socket_t clientSock = accept(lsock, &clientSockAdress, nullptr);
                    if (clientSock != SOCKET_INVALID) {
                        socketList.push_back(clientSock);
                        std::cout << "New connection accepted\n";
                    }
                }
                       
				for (itr = socketList.begin(); itr != socketList.end(); itr++) {
                    if (FD_ISSET(*itr, &socketSet)) {
                        char buffer[128];
                        int rec = recv(*itr, (char*)&buffer, sizeof(buffer), 0);
                        if (rec == 0) {
							shutdown(*itr, SD_BOTH);
							closesocket(*itr);
							socketList.erase(itr);
                            std::cout << "Connection closed " << "\n";
                            --itr;
                        } else if(checkError(rec)){
                            return 0;
                        }
                        else{
							if (strcmp(buffer, "quit") == 0 || strcmp(buffer,"servquit") == 0) {
                                notdone = false;
                            }
                            std::cout << "Data received: " << buffer << "\n";
                        }
                    }

                }

            }
          
    }
    std::cout << "Server is shutting down";
    shutdown(lsock, SD_BOTH);
	closesocket(lsock);
	for (int sock : socketList) {
        shutdown(sock, SD_BOTH);
        closesocket(sock);
    }
    CloseSocketLib
    std::cin.get();
}


