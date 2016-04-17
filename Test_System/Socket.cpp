#pragma once
#include "lib/System_Library.hpp"
namespace System {
	Socket::Socket(DOMAIN domain, SOCKET_TYPE type, PROTOCOL protocol)
	{
#ifdef WINDOWS
		if (WSAStartup(MAKEWORD(2, 2), &this->wsaData) != 0) 
		{

		}
#endif // WINDOWS

	}
}