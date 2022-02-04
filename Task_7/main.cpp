#include <thread>
#include <iostream>
#include <ctime>
#include <cstdlib>

bool* isDone = new bool[8];

int* array = new int[80];

int* doneArray = new int[8];

int result = 0;

void summArrayMT(int number)
{
	int res = 0;
	int start = number * 10;
	int end = number * 10 + 10;
	for (int i = start; i < end; i++)
	{
		res += array[i];
	}
	doneArray[number] = res;
	isDone[number] = true;
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < 80; i++)
	{
		array[i] = (rand() % 10);
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
	{
		isDone[i] = false;
		doneArray[i] = 0;
		std::thread thread(summArrayMT, i);
		thread.detach();
	}

	while(!(isDone[0] && isDone[1] && isDone[2] && isDone[3] && isDone[4] && isDone[5] && isDone[6] && isDone[7]));

	for(int i = 0; i < 8; i++)
	{		
		result += doneArray[i];
		std::cout << doneArray[i] << " ";
	}
	std::cout << std::endl << result << std::endl;
}