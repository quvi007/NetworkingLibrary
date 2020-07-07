#pragma once

#include <WS2tcpip.h>
#include <iostream>
#include <string>
#include "Socket.h"

#pragma comment(lib, "ws2_32.lib")
#define MAX_CHAR 4096

class ServerSocket {
	WSAData wsData;
	int serverSocket;
	Socket clientSocket;
	sockaddr_in serverSocketInfo;
public:
	ServerSocket(int port);
	Socket& acceptConnection();
	void close();
};

