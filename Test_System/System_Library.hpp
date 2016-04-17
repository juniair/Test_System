#ifndef _SYSTEM_LIBRARY_HPP_
#define _SYSTEM_LIBRARY_HPP_
#include "lib/Library.hpp"




namespace System {
	
	class MySQL {

	};

	class Log {

	};
	
	class Socket {	
	private:
#ifdef WINDOWS
		WSADATA wsaData;
#endif
		
		SOCKET server, client;
		SOCKET_SIZE clinetAddressSize;
		SOCKADDR_IN serverAddress, clientAddress;

		void init() {};
	public:
		Socket(DOMAIN = PF_INET, SOCKET_TYPE = TCP, PROTOCOL = 0) {};
		
		void connect(IP = INADDR_ANY, PORT = 9999, PROTOCOL = AF_INET) {};
		

		~Socket() {};
		
		
	};

	

	
}
#endif
