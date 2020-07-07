#pragma once
#include <iostream>
#include <string>
#include <WS2tcpip.h>
#define MAX_CHAR 4096

#pragma comment(lib, "ws2_32.lib")

class Socket {
	WSAData wsData;
	int clientSocket;
	sockaddr_in serverSocketInfo;
	friend class ServerSocket;
public:
	Socket();
	Socket(std::string host, int port);
	std::string readLine();
	void println(std::string str);
	void close();
};

