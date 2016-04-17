#pragma once
#include "System_Library.hpp"
namespace System {
	Socket::Socket(DOMAIN domain, SOCKET_TYPE type, PROTOCOL protocol)
	{
#ifdef WINDOWS
		if (WSAStartup(MAKEWORD(2, 2), &this->wsaData))
		{

		}
#endif // WINDOWS
		


	}

	Socket::~Socket()
	{
		{
#ifdef WINDOWS
			WSACleanup();
			
#else
			close(client);
			close(server);
#endif
		}
	}
}