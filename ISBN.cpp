#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int kolvo;
	long long val;
	int kontrol;
	int sum = 0;
	long long ten = 1000000000000;
	long long newval;
	int newkontr;
	cout << "������� ���������� N" << endl;
	cin >> kolvo;
	for (int i = 0; i < kolvo; i++)
	{
		cout << endl << "������� 13-�� ������� �����" << endl;
		cin >> val;
		if ((val / 1000000000000 > 9) || (val / 1000000000000 < 1))
		{
			cout << "����� �� 13-�� �������" << endl;
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
				cout << "����� " << val << " -- �������������� ISBN-13" << endl;
			}
			else
			{
				cout << "����� " << val << " -- �� �������������� ISBN-13" << endl;
			}
			sum = 0;
			ten = 1000000000000;
		}
	}
	cout << "������ ��������" << endl;
	system("pause");

}