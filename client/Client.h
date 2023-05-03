// Client.h: arquivo de inclusão para arquivos de inclusão padrão do sistema,
// ou arquivos de inclusão específicos a um projeto.

#pragma once

#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "Ws2_32.lib")

#define MAX_MESSAGE_BUFFER	(512)
#define HOST_IP				"127.0.0.1"
#define HOST_PORT			(3030)


namespace Client {
	char message[MAX_MESSAGE_BUFFER];
	char receiveMessage[MAX_MESSAGE_BUFFER];
	sockaddr_in Server;
}