#define PORT 777
#define ADRESS "127.0.0.1"

#pragma once

#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <Windows.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class web
{
private:

	unsigned port;

	SOCKET mainSocket, clientSocket;
	sockaddr_in local_addr, client_addr;
	char buffer[20 * 1024];
	int ErrorIndication;
	void (*function)(web &w);

	static WSADATA socketInfo;
	static int client_addr_size;
	static unsigned nSockets;

	static DWORD WINAPI client(LPVOID WEB);

public:
	web(int port);
	web(SOCKET &Socket, sockaddr_in sa);
	web(int port, const char *adress);

	void Listen(void(f(web &w)));
	bool sendMessage(const char* message,int n=0);
	char *getMessage();
	bool connect();
	~web();
};

