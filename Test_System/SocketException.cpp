#ifndef _SOCKET_EXCEPTION_CPP_HPP
#define _SOCKET_EXCEPTION_CPP_HPP
#include "System_Library.hpp"
namespace System {
	SocketException::SocketException(TAG tag, MESSAGE message)
	{
		this->tag = tag;
		this->message = message;
	}
	SocketException::~SocketException() noexcept
	{
	}
	const char* SocketException::what() const noexcept
	{

	}
}
#endif // !_SOCKET_EXCEPTION_CPP_H