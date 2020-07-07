#include "ServerSocket.h"

ServerSocket::ServerSocket(int port) {
	WSAStartup(MAKEWORD(2, 2), &wsData);
	serverSocketInfo.sin_family = AF_INET;
	serverSocketInfo.sin_port = htons(port);
	serverSocketInfo.sin_addr.S_un.S_addr = INADDR_ANY;
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	bind(serverSocket, (sockaddr*) &serverSocketInfo, sizeof(serverSocketInfo));
	listen(serverSocket, SOMAXCONN);
}

Socket& ServerSocket::acceptConnection() {
	 clientSocket.clientSocket = accept(serverSocket, NULL, NULL);
	 closesocket(serverSocket);
	 return clientSocket;
}

void ServerSocket::close() {
	WSACleanup();
}