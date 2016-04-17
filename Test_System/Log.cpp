#ifndef _LOG_CLASS_
#define _LOG_CLASS_
#include "lib/System_Library.hpp"

namespace System {
	static void Log::print(TAG tag, MESSAGE message)
	{
		auto now = std::chrono::system_clock::now();

	}
}

#endif // !_LOG_CLASS_