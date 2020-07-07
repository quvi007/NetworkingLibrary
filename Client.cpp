#include <iostream>
#include <string>
#include <thread>
#include "Socket.h"

#define MAX_CHAR 4096

using namespace std;

string serverTxt, clientTxt;
char buff[MAX_CHAR];


void receiveFromServer(Socket &clientSocket) {
	while (true) {
		//this_thread::sleep_for(chrono::milliseconds(10));
		memset(buff, 0, sizeof(buff));
		serverTxt = clientSocket.readLine();
		if (serverTxt == "") {
			cout << "The Server Disconnected!\n";
			break;
		}
		cout << serverTxt << "\n";
	}
}

void sendToServer(Socket &clientSocket) {
	while (true) {
		//this_thread::sleep_for(chrono::milliseconds(10));
		getline(cin, clientTxt);
		clientTxt = "Client: " + clientTxt;
		clientSocket.println(clientTxt);
	}
}

int main() {
	Socket clientSocket("127.0.0.1", 8907);

	cout << "You are connected with CitadelX Server. Type anything.\n";

	thread t1 (receiveFromServer, ref(clientSocket));
	thread t2 (sendToServer, ref(clientSocket));
	
	t1.join();
	t2.join();

	clientSocket.close();
	return 0;
}