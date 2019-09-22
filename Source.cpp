#include <iostream>
using namespace std;

int main()
{
	/*int five = 5;
	float two = 2.0F;
	cout << five/static_cast<int>(two) << endl;*/
	//bool b = 5 < 7;
	//if (b)
	//{
	//}
	//int i = 0;
	//do
	//{
	//	cout << "hello world" << endl;
	//}while (i > 10)
	//for (int i = 0; i < 10; )
	//{
	//	/*cout << i << endl;*/
	//	++i;
	//}
	//int value = 10;
	//cout << ++value << endl;
	/*cout << value++ << endl;*/



	//Homework
	setlocale(LC_ALL, "Russian");
	int kolvo;
	long long val;
	int kontrol;
	int sum = 0;
	long long ten = 1000000000000;
	long long newval;
	int newkontr;
	cout << "Введите количество N" << endl;
	cin >> kolvo;


	for (int i = 0; i < kolvo; i++)
	{
		cout << endl << "Введите 13-ти значное число" << endl;
		cin >> val;
		if ((val / 1000000000000 > 9) || (val / 1000000000000 < 1))
		{
			cout << "Число не 13-ти значное" << endl;
		}
		else
		{
			newval = val - (val % 10);
			for (int i = 0; i < 12; i++)
			{
				if (i % 2 == 0)
				{
					sum = sum + newval / ten % 10 * 1;
					ten = ten / 10;
				}
				else
				{
					sum = sum + newval / ten % 10 * 3;
					ten = ten / 10;
				}
			}
			kontrol = sum % 10;
			newkontr = 10 - kontrol;
			if ((val % 10) == newkontr)
			{
				cout << "Число " << val << " -- действительное ISBN-13" << endl;
			}
			else
			{
				cout << "Число " << val << " -- не действительное ISBN-13" << endl;
			}
			sum = 0;
			ten = 1000000000000;
		}
	}
	cout << "РАБОТА ОКОНЧЕНА" << endl;
}