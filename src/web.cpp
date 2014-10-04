#include "../include/web.h"

#pragma warning(disable : 4996)

unsigned web::nSockets = 0;
WSADATA web::socketInfo;
int web::client_addr_size;

web::web(int port) :port(port)
{

	ErrorIndication = 0;
	if (nSockets == 0)
	{
		client_addr_size = sizeof(client_addr);
		if (WSAStartup(0x202, &socketInfo))
		{
			ErrorIndication = -1;
		}

		//cout << "start" << endl;
	}
	nSockets++;


	//cout << "open port " << nSockets << endl;

	if ((mainSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		ErrorIndication = -2;
	}

	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(PORT);
	local_addr.sin_addr.s_addr = 0;
}
web::web(SOCKET &Socket, sockaddr_in sa)
{
	ErrorIndication = 0;
	if (nSockets == 0)
	{
		client_addr_size = sizeof(client_addr);
		if (WSAStartup(0x202, &socketInfo))
		{
			ErrorIndication = -1;
		}

		//cout << "start" << endl;
	}
	nSockets++;


	//cout << "open socket, sock_addr" << nSockets << endl;

	ErrorIndication = 0;
	mainSocket = Socket;
	local_addr = sa;
}

web::web(int port, const char* adress) :port(port)
{
	HOSTENT *hst;
	ErrorIndication = 0;
	if (nSockets == 0)
	{
		client_addr_size = sizeof(client_addr);
		if (WSAStartup(0x202, &socketInfo))
		{
			ErrorIndication = -1;
		}

		//cout << "start" << endl;
	}
	nSockets++;


	//cout << "open port, adress" << nSockets << endl;

	if ((mainSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		ErrorIndication = -2;
	}

	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(PORT);
	if (inet_addr(adress) != INADDR_NONE)
		local_addr.sin_addr.s_addr = inet_addr(adress);
	else if (hst = gethostbyname(adress))
		((unsigned long*)&local_addr.sin_addr)[0] = ((unsigned long **)hst->h_addr_list)[0][0];
	else
	{
		ErrorIndication = - 5;
	}

}


web::~web()
{
	nSockets--;
	closesocket(mainSocket);
	cout << "close " << nSockets << endl;
	if (nSockets == 0)
	{
		WSACleanup();
		///cout << "all sockets closed" << endl;
	}

}

void web::Listen(void(f(web &w)))
{

	if (bind(mainSocket, (sockaddr *)&local_addr, sizeof(local_addr)))
	{
		ErrorIndication = -2;
	}
	if (listen(mainSocket, 0x100))
	{
		ErrorIndication = -2;
	}
	while ((clientSocket = accept(mainSocket, (sockaddr*)&client_addr, &client_addr_size)))
	{

		HOSTENT *hst;
		hst = gethostbyaddr((char *)&client_addr.sin_addr.s_addr, 4, AF_INET);
		DWORD thID;
		web *Socket =
		new web
		(clientSocket, client_addr)
   ;
		Socket->function = f;
		CreateThread(NULL, NULL, client, (LPVOID) Socket, NULL, &thID);

	}
}
DWORD WINAPI web::client(LPVOID WEB)
{
	((web *)WEB)->function(*((web *)WEB));
	delete ((web *)WEB);
	return 0;
}
bool web::sendMessage(const char* message,int n)
{
	strcpy(buffer, message);
	int sendmessage= send(mainSocket, buffer, 1024, 0);
	if (sendmessage && sendmessage != SOCKET_ERROR)
		return true;
	return false;
}
char * web::getMessage()
{
	recv(mainSocket, buffer, 1024, 0);
	return buffer;
}
bool web::connect()
{
	return (::connect(mainSocket, (sockaddr *)&local_addr, sizeof(local_addr)));
}
