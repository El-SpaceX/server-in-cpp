#include "Client.h"

using namespace std;

int main()
{
	WSADATA	wsdata;


	if (WSAStartup(MAKEWORD(2, 2), &wsdata) != 0) {
		cout << "\033[1;31m[ERROR]\033[m Failed in WSAStartup. Code: " << WSAGetLastError() << endl;
		return EXIT_FAILURE;
	}

	SOCKET sock;
	if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
		cout << "\033[1;31m[ERROR]\033[m Failed to create the socket." << endl;
		WSACleanup();
		return EXIT_FAILURE;
	}

	Client::Server.sin_family = AF_INET;
	Client::Server.sin_addr.S_un.S_addr = inet_addr(HOST_IP);
	Client::Server.sin_port = htons(HOST_PORT);


	cout << "\033[1;32m[SUCESS]\033[m Program started successfully." << endl;
	while (true) {
		cout << "Write your message to the server. (use /quit to exit the server): ";
		cin.getline(Client::message, sizeof Client::message);

		if (!_strcmpi(Client::message, "/quit")) {
			cout << "\033[1;33m[WARNING]\033[m You left the program" << endl;
			cout << "\033[1;32m[SUCESS]\033[m Finished program." << endl;;
			break;
		}
		size_t messageLen = strlen(Client::message);
		
		if (messageLen == 0) {
			cout << "\033[1;31m[ERROR]\033[m Mensagem em branco." << endl;
			continue;
		}


		if (sendto(sock, Client::message, messageLen, 0, (sockaddr*)&Client::Server, sizeof Client::Server) == SOCKET_ERROR) {
			cout << "\033[1;31m[ERROR]\033[m Failed to send the message." << endl;
			continue;
		}
		
		sockaddr_in RecvAddr;
		int Recvlen = (int)sizeof(sockaddr_in);
		if ((recvfrom(sock, Client::receiveMessage, MAX_MESSAGE_BUFFER, 0, (struct sockaddr*)&RecvAddr, &Recvlen)) == SOCKET_ERROR) {
			cout << "\033[1;31m[ERROR]\033[m Failed in read message from server." << endl;
			continue;
		}
		
		cout << "\033[1;32m[SERVER RESPONSE]\033[m " << Client::receiveMessage << endl;

	}
	closesocket(sock);
	WSACleanup();
	return 0;
}
