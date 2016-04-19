#ifndef _SYSTEM_LIBRARY_HPP_
#define _SYSTEM_LIBRARY_HPP_
#include "lib/Library.hpp"

namespace System {
	class DataBase {
		//__FUNCTION__
	};

	class SocketException : public std::exception {
	private:
		std::string tag;
		std::string message;
	public:
		SocketException(TAG, MESSAGE);
		~SocketException() noexcept;
		virtual const char* what() const noexcept;
		friend std::ostream& operator<< (std::ostream&, SocketException&);
	};

	class Socket {	
	private:
	#ifdef WINDOWS
		WSADATA wsaData;
	#endif	
		SOCKET server, client;
		SOCKET_SIZE clinetAddressSize;
		SOCKADDR_IN serverAddress, clientAddress;

		void initialize();
	public:
		Socket(DOMAIN = PF_INET, SOCKET_TYPE = TCP, PROTOCOL = 0);
		~Socket();
		void connect(IP = INADDR_ANY, PORT = 9999, PROTOCOL = AF_INET);
	};

	class Log {
	private:
		void makeLogFile(std::string logInfo) noexcept;
	public:
		static void print(TAG, MESSAGE) noexcept;

	};
} // namespce System

#endif
