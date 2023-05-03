#include "server.h"

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	WSADATA wsdata;
	SOCKET sock;


	struct sockaddr_in server, client; 

	if (WSAStartup(MAKEWORD(2, 2), &wsdata) != 0) {
		cout << "\033[1;31mError starting WSAStartup. Error-Code: " << WSAGetLastError() << "\033[m" << endl;
		return 0;
	}


	cout << "\033[1;32mWSAStartup started successfully.\033[m" << endl;

	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	if (sock == INVALID_SOCKET) {
		cout << "Failed to create socket." << endl;
		return 0;
	}


	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(3030);

	if (bind(sock, (struct sockaddr*)&server, sizeof server) == SOCKET_ERROR) {
		cout << "\033[1;31mFailed to turn on the server. Code: " << WSAGetLastError() << "\033[m" << endl;
		return 0;
	}

	int lenClient = sizeof(struct sockaddr_in);
	while (true) {
		int lenRecV = 0;

		if((lenRecV = recvfrom(sock, tempMessage, MAX_BUFFER_MESSAGE, 0, (struct sockaddr*)&client, &lenClient)) == SOCKET_ERROR) {
			cout << "\033[2;32mFailed to read message from " << inet_ntoa(client.sin_addr) << ':' << client.sin_port << "0\33[m" << endl;
			continue;
		}
		cout << "\033[2;33mResponse received from " << inet_ntoa(client.sin_addr) << ':' << client.sin_port << ". Size: " << lenRecV << "\033[m" <<endl;
		
		sendto(sock, lastMessage, MAX_BUFFER_MESSAGE, 0, (struct sockaddr*)&client, sizeof(client));
		cout << "\033[2;32mReply sent to " << inet_ntoa(client.sin_addr) << ':' << client.sin_port << "\033[m" << endl;

		strcpy_s(lastMessage, tempMessage);
		memset(tempMessage, 0, sizeof tempMessage);

	}

	closesocket(sock);
	WSACleanup();
	cout << "\033[2;32mServer finished.\033[m" << endl;
	return 0;
}
