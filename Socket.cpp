#include "Socket.h"

Socket::Socket(std::string host, int port) {
	WSAStartup(MAKEWORD(2, 2), &wsData);
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	serverSocketInfo.sin_family = AF_INET;
	serverSocketInfo.sin_port = htons(port);
	inet_pton(AF_INET, host.c_str(), &serverSocketInfo.sin_addr);
	connect(clientSocket, (sockaddr*)&serverSocketInfo, sizeof(serverSocketInfo));
}

Socket::Socket() {

}

std::string Socket::readLine() {
	std::string str;
	char buff[MAX_CHAR];
	memset(buff, 0, sizeof(buff));
	int rSize = recv(clientSocket, buff, sizeof(buff), 0);
	str = std::string(buff, 0, rSize);
	return str;
}

void Socket::println(std::string str) {
	send(clientSocket, str.c_str(), str.length() + 1, 0);
}

void Socket::close() {
	closesocket(clientSocket);
}