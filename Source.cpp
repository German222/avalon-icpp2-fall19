#include <iostream>
#include <limits>
using namespace std;

/*const int SIZE = 5;
int sum(int a[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += a[i];
	}
	return sum;
}*/

   /* int CountLength(char b[])
{
	int i = 0;
	int size = 0;
	while (b[i] != '\0')
	{
		size++;
		
	}
	return size;
}*/

//int findmax(int a[], int size)
//{
//	int max = a[0];
//
//	for (int i = 1; i < size; ++i)
//	{
//		if (a[i] > max)
//		{
//			max = a[i];
//		}
//	}
//	return max;
//}

//int findmoda(int data[], int size)
//{
//	int count = 0;
//	int value = 0;
//	for (int i = 0; i < size; ++i)
//	{
//		int current = data[i];
//		int currentCount = 1;
//		for (int j = i + 1; j < size; ++j)
//		{
//			if (data[j] == current)
//			{
//				++count;
//			}
//		}
//		if (currentCount > count)
//		{
//			count = currentCount;
//			value = current;
//		}
//	}
//	return value;
//}

void sortData(int data[], int size)
{
	bool isSwap = false;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1 - i ;++j)
		{
			if (data[j] > data[j+1])
			{
				int temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
				isSwap = true;
			}
		}
		if (!isSwap) return;
		isSwap = false;
	}
}

int findmodasort(int data[], int size)
{
	int countmax = 1;
	int value = data[0];
	int count = 1;
	int valuemax = data[0];
	for (int i = 1; i < size; ++i)
	{
		if (data[i-1] == data[i])
		{
			++countmax;
		}
		else
		{
			if (count > countmax)
			{
				countmax = count;
				valuemax = data[i-1];
				count = 1;
			}
		}
	}
	return value;
}

int findmoda(int data[], int size)
{
	sortData(data, size);
	return findmodasort(data, size);
}

void prinddata2d(int * a[], int sizeX, int sizeY)
{
	for(int i = 0; i < sizeY; ++i)
	{
		for (int j = 0; j < sizeX; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	/*int a[] = { 1,2,3,4,5 };
	size_t
	sum(a,SIZE);
	cout << sizeof(a)/ sizeof(int) << endl;*/

	/*int s[10] = {};
	char a[] = { 'a','b', 'c', '\0' };
	char b[] = "Hello";
	cout << s << endl;
	cout << a << endl;
	cout << b << endl;
	cout << CountLength(a) << endl;*/
	
	/*int data[] = { 4,7,3,8,9,7,3,9,9,3,3,10 };
	sortData(data, sizeof(data) / sizeof(int));
	cout << findmoda(data, sizeof(data)/sizeof(int)) << endl;*/

	int a[2][3] = { {2,4,6},{4,8,10} };
	p
}