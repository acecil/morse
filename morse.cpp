
#include <iostream>

#include "morse.h"

using morse::morse_code;
using morse::to_string;
using morse::operator"" _m;

int main()
{
	auto abc = ".- -... -.-."_m;
	std::cout << abc << " = " << to_string(abc) << std::endl;

	auto helloworld = ".... . .-.. .-.. ---  .-- --- .-. .-.. -.."_m;
	std::cout << helloworld << " = " << to_string(helloworld) << std::endl;

	std::cout << (helloworld == morse_code("hello world")) << std::endl;
	
	return 0;
}
