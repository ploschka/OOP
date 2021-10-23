#include <iostream>
#include <cmath>
#define INVALID_INPUT -1
#define BELOW_ZERO_INPUT -2

int main()
{
	int a, b;

	std::cout << "Первый катет = ";
	std::cin >> a;
	std::cout << "Второй катет = ";
	std::cin >> b;
	if (std::cin.fail())
	{
		exit(INVALID_INPUT);
	}
	if ((a <= 0) || (b <= 0))
	{
		exit(BELOW_ZERO_INPUT);
	}
	float c = sqrt(pow(a, 2) + pow(b, 2));
	std::cout << "S = " << ((a * b)/2) << std::endl << "P = " << (a + b + c) << std::endl;
	return 0;
}
