#pragma once
#include "System_Library.hpp"
namespace System {
	Socket::Socket(DOMAIN domain, SOCKET_TYPE type, PROTOCOL protocol)
	{
#ifdef WINDOWS
	
		switch (WSAStartup(MAKEWORD(2, 2), &this->wsaData)) {
			case WSASYSNOTREADY:
			case WSAVERNOTSUPPORTED:
			case WSAEINPROGRESS:
			case WSAEPROCLIM:
			case WSAEFAULT:					
			default:
				if (1 > 0)
					throw new std::exception("Winsock StartUp Exception!");
				break;
		}
	
	

		
#endif // WINDOWS

	}

	void Socket::connect(IP ip, PORT port, PROTOCOL protocol)
	{
		std::cout << "Hi" << std::endl;
	}

	Socket::~Socket()
	{
		{
#ifdef WINDOWS
			WSACleanup();
			
#else
			close(this->client);
			close(this->server);
#endif
		}
	}
}