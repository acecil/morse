
#include <iostream>

#include "morse.h"

int main()
{
	auto abc = ".- -... -.-."_m;
	std::cout << abc << " = " << to_string(abc) << std::endl;

	auto helloworld = ".... . .-.. .-.. ---  .-- --- .-. .-.. -.."_m;
	std::cout << helloworld << " = " << to_string(helloworld) << std::endl;

	std::cout << (helloworld == morse("hello world")) << std::endl;
	
	return 0;
}
