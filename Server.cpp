#include <iostream>
#include "ServerSocket.h"
#include <thread>

using namespace std;


string serverTxt, clientTxt;
char buff[MAX_CHAR];

void receiveFromClient(Socket& clientSocket) {
	while (true) {
		//this_thread::sleep_for(chrono::milliseconds(10));
		memset(buff, 0, sizeof(buff));
		clientTxt = clientSocket.readLine();
		if (clientTxt == "") {
			cout << "The Client Disconnected!\n";
			break;
		}
		cout << clientTxt << "\n";
	}
}

void sendToClient(Socket& clientSocket) {
	while (true) {
		//this_thread::sleep_for(chrono::milliseconds(10));
		getline(cin, serverTxt);
		serverTxt = "Server: " + serverTxt;
		clientSocket.println(serverTxt);
	}
}

int main() {
	ServerSocket serverSocket = ServerSocket(8907);
	Socket &clientSocket = serverSocket.acceptConnection();

	cout << "You are connected with CitadelX Client. Type anything.\n";

	thread t1(receiveFromClient, ref(clientSocket));
	thread t2(sendToClient, ref(clientSocket));

	t1.join();
	t2.join();

	clientSocket.close();
	serverSocket.close();
	return 0;
}