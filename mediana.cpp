#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;
int main()
{
	int a = 0;
	int b = 1;
	setlocale(LC_ALL, "RUS");
	int N = 10;	
	int nerab = -1;
	int** mas;
	mas = new int* [N];
	
	for (int i = 0; i < N; i++) 
	{   
		mas[i] = new int[12];    
	}
	mas[0][0] = 0;
	int arr[2];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			arr[0] = -1;
			arr[1] = GetRandomValue(1000, 100000);			
			int fff = GetRandomValue(a, b);
			mas[i][j] = arr[fff];
			cout << mas[i][j] << "   ";
		}
		cout << endl;
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < 12 - 1; i++) {
			for (int j = 0; j < 12 - i - 1; j++) {
				if (mas[k][j] > mas[k][j + 1]) {					
					int temp = mas[k][j];
					mas[k][j] = mas[k][j + 1];
					mas[k][j + 1] = temp;
				}
			}
		}
	}
	cout << endl;
	cout << "Отсортированный массив:" << endl;
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << mas[i][j] << "   ";
		}
		cout << endl;
	}
	int mediana = 0;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			for (int k = 0; k < 12; k++)
			{
				if (mas[i][k] == -1)
				{
					count++;
				}
				else
				{
					break;
				}
			}
			if ((12 - count) % 2 == 0)
				mediana = (mas[i][(12 - count) / 2 + count - 1] + mas[i][(12 - count) / 2 + count]) / 2;
			else
				mediana = mas[i][((12 - count) / 2) + count];
			count = 0;
		}
		cout << endl;
		cout << mediana << endl;
	}
}
