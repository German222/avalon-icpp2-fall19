#include <string>
#include <iostream>
#include "Extention.hpp"
#include <algorithm>
using namespace ext;
using namespace std;
struct Student
{
	int Id;
	int Grade;
	string Name;
	Student(int Id, int Grade, string Name)
	{
		this->Id = Id;
		this->Grade = Grade;
		this->Name = Name;
	}
	Student()
	{
		this->Id = 0;
		this->Grade = 0;
		this->Name = "";
	}
	void Show_id()
	{
		cout << Id << "  " << Grade << "  " << Name << endl;
	}
	void Show_grade()
	{
		cout << Grade << "  " << Id << "  " << Name << endl;
	}
	void Show_name()
	{
		cout << Name << "  " << Id << "  " << Grade << endl;
	}

};

void bubble_sort_id(Student* mas, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (mas[j].Id > mas[j + 1].Id) {
				Student temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}
}
void bubble_sort_grade(Student* mas, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (mas[j].Grade > mas[j + 1].Grade) {
				Student temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}
}
void bubble_sort_name(Student* mas, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (mas[j].Name > mas[j + 1].Name) {
				Student temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int N = 100;
	string criterion;
	setlocale(LC_ALL, "RUS");
	cout << "Введите критерий сортировки: Id/Grade/Name" << endl;
	cin >> criterion;
	int len = 0;
	string name;

	Student* mas = new Student[N];
	for (int i = 0; i < N; i++)
	{
		len = GetRandomValue(3, 5);
		for (int j = 0; j < 1; j++)
		{
			name = GetRandomValue('A', 'Z');
			for (int k = 0; k < len; k++)
			{
				name += GetRandomValue('a', 'z');
			}
		}
		mas[i] = Student(GetRandomValue(1, 1000), GetRandomValue(1, 100), name);
		//mas[i].Show();
		name = "";
	}
	if (criterion == "Id")
	{
		bubble_sort_id(mas, 100);
		for (int i = 0; i < N; i++)
		{
			mas[i].Show_id();
		}
		system("pause");
	}
	else if (criterion == "Grade")
	{
		bubble_sort_grade(mas, 100);
		for (int i = 0; i < N; i++)
		{
			mas[i].Show_grade();
		}
		system("pause");
	}
	else if (criterion == "Name")
	{
		bubble_sort_name(mas, 100);
		for (int i = 0; i < N; i++)
		{
			mas[i].Show_name();
		}
		system("pause");
	}
}