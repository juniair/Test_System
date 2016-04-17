#pragma once
#ifndef _LOG_CLASS_
#define _LOG_CLASS_
#include "lib/System_Library.hpp"

namespace System {
	void Log::Log
	{
		std::cout << tag << " " << message << std::endl;
	}
}

#endif // !_LOG_CLASS_