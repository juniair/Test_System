#include "System_Library.hpp"
namespace System {

	void Log::makeLogFile(std::string logInfo) noexcept
	{
		std::fstream file;
		file.open("Log.txt", std::ios::app);
		file << logInfo.c_str() << std::endl;
		file.close();
		
	}

	void Log::print(TAG tag, MESSAGE message)  noexcept
	{
		std::string logInfo;
#ifdef WINDOWS
		logInfo = __TIMESTAMP__ + std::string(" ") + tag + std::string(" : ") + message;
		
#else
		time_t now = time(NULL);
		logInfo = std::string(ctime(&now)) + std::string(" ") + tag + std::string(" : ") + message;
#endif
		
		std::cout << logInfo.c_str() << std::endl;
		
	}

	void Log::print(MESSAGE message) noexcept
	{
		std::stringstream logInfo;
#ifdef WINDOWS
		logInfo << __TIMESTAMP__ << std::string(message);

#else
		time_t now = time(NULL);
		logInfo = std::string(ctime(&now)) + std::string(" ") + message;
#endif

		std::cout << logInfo.str() << std::endl;
	}
}

