#ifndef _TCP_CPP_
#define _TCP_CPP_
#include "System_Library.hpp"
namespace System 
{
	TCP::TCP(void) : Socket(SOCK_STREAM)
	{
	}

	TCP::TCP(const TCP &tcp) : Socket()
	{
		this->_socket_id = tcp._socket_id;
		this->_isOpened = tcp._isOpened;
		this->_isBinded = tcp._isBinded;
	}

	IP TCP::ip(void)
	{
		return this->_address.ip();
	}

	PORT TCP::port(void)
	{
		return this->_address.port();
	}

	Address TCP::address(void)
	{
		return Address(this->_address);
	}

	void TCP::listen_on_port(PORT port, LISTENER listener)
	{
		Socket::listen_on_port(port);

		if (listen(this->_socket_id, listener) != 0)
		{
			std::stringstream error;
			error << "[listen_on_port] with [port=" << port << "] [listeners=" << listener << "] Cannot bind socket";
			throw SocketException(error.str());
		}
	}

	void TCP::connect_to(Address address)
	{
		if (this->_isBinded)
		{
			throw SocketException("[connect_to] Socket already binded to a port, use another socket");
		}

		if (!this->_isOpened)
		{
			this->open();
		}

		if(connect(this->_socket_id, (SOCKADDR*)&address, sizeof(SOCKADDR_IN)) < 0)
		{
			std::stringstream error;
			error << "[connect_to] with [address=" << address << "] Cannot connect to the specified address";
			throw SocketException(error.str());
		}
				
		this->_isBinded = true;
	}
}
#endif // !_TCP_CPP_