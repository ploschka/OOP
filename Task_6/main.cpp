#include <iostream>
#include "Base64.h"

#define tos_tr(x) #x

int main()
{
	std::string enc;
	std::string dec;

	std::cout << "String to encode : ";
	std::cin >> enc;

	std::cout << "String to decode : ";
	std::cin >> dec;

	std::cout << std::endl << "Encoded string :\n" << Base64::encode(enc) << std::endl << "Decoded string :\n" << Base64::decode(dec) << std::endl;;
}