#include "System_Library.hpp"
#include <typeinfo>
class Polymorphic {virtual void member(){}};

int main () {
	try {
		System::Socket *socket = 0;
		typeid(socket);
	}
	catch (std::exception e)
	{
		std::cerr << e.what();
	}
	
  return 0;
}