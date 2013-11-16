
#include <iostream>

#include "morse.h"

int main()
{
	auto m0 = ".- -... -.-."_m;
	auto m1 = ".... . .-.. .-.. --- .-- --- .-. .-.. -.."_m;

	std::cout << m0 << std::endl;
	std::cout << m1 << std::endl;

	return 0;
}
