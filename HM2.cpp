#include <string>
#include <iostream>
#include "Header.hpp"
using namespace ext;
using namespace std;

struct Student
{
	int Id;
	int Graid;
	string Name;
}

int main()
{
	string data[4];

	for (int i = 0; i < 4; ++i)
	{
		int length = GetRandomValue(3, 6);
		char letter = GetRandomValue('A', 'Z');
		data[i] += letter;

		for (int j = 0; j < length; ++j)
		{
			data[i] += GetRandomValue('a', 'z');
		}
	}
}
