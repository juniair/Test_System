#pragma once
#include "System_Library.hpp"
namespace System {
	Socket::Socket(DOMAIN domain, SOCKET_TYPE type, PROTOCOL protocol)
	{
#ifdef WINDOWS
		switch (WSAStartup(MAKEWORD(2, 2), &this->wsaData)) {
			case WSASYSNOTREADY:
				break;
			case WSAVERNOTSUPPORTED:
				break;
			case WSAEINPROGRESS:
				break;
			case WSAEPROCLIM:
				break;
			case WSAEFAULT:
				break;
			default:
				break;
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