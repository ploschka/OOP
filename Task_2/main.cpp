#include <iostream>
#define INVALID_INPUT -1
#define ZERO_INPUT -2

int factorial(int value)
{
	int result = 1;
	for (int i = 1; i <= value; i++)
	{
		result *= i;
	}
	return result;
}

void checkInput(const int& val)
{
	if (std::cin.fail())
	{
		exit(INVALID_INPUT);
	}
	if (val == 0)
	{
		exit(ZERO_INPUT);
	}
}

int main()
{
	int count;
	std::cout << "Количество чисел = ";
	std::cin >> count;
	checkInput(count);
	int* arr = new int[count];
	std::cout << "Введите " << count << " чисел через пробел: ";
	for (int i = 0; i < count; i++)
	{
		std::cin >> arr[i];
		checkInput(arr[i]);
	}
	std::cout << "Числа и их факториалы: ";
	for (int i = 0; i < count; i++)
	{
		std::cout << arr[i] << ":" << factorial(arr[i]) << " ";
	}
	std::cout << std::endl;
	delete[] arr;
	return 0;
}
