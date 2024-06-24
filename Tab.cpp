#include <stdio.h>
#include <iostream>
#include <string>
#include <limits>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	printf("%s", "Тип переменной\t\t|\tРазмер,\t|\t       Значение\t        |  Количество   |\n ");
	printf("%s", "\t\t\t|\tбайт\t|  Минимальное  | Максимальное  |  значимых бит |\n");

	printf("bool\t\t\t|\t%d\t|\t%d\t|\t%d\t|\t%u\t|\n", sizeof(bool), numeric_limits<bool>::min(), numeric_limits<bool>::max(), numeric_limits<bool>::digits);

	printf("unsigned short\t\t|\t%d\t|\t%d\t|\t%d\t|\t%u\t|\n", sizeof(unsigned short), numeric_limits<unsigned short>::min(), numeric_limits<unsigned short>::max(), numeric_limits<unsigned short>::digits);

	printf("short\t\t\t|\t%d\t|\t%d\t|\t%d\t|\t%u\t|\n", sizeof(short), numeric_limits<short>::min(), numeric_limits<short>::max(), numeric_limits<short>::digits);

	printf("unsigned int\t\t|\t%d\t|\t%d\t|   %u\t|\t%u\t|\n", sizeof(unsigned int), numeric_limits<unsigned int>::min(), numeric_limits<unsigned int>::max(), numeric_limits<unsigned int>::digits);

	printf("int\t\t\t|\t%d\t|   %d\t|   %d\t|\t%u\t|\n", sizeof(int), numeric_limits<int>::min(), numeric_limits<int>::max(), numeric_limits<int>::digits);

	printf("unsigned long\t\t|\t%d\t|\t%d\t|   %u\t|\t%u\t|\n", sizeof(unsigned long), numeric_limits<unsigned long>::min(), numeric_limits<unsigned long>::max(), numeric_limits<unsigned long>::digits);

	printf("long\t\t\t|\t%d\t|   %d\t|   %d\t|\t%u\t|\n", sizeof(long), numeric_limits<long>::min(), numeric_limits<long>::max(), numeric_limits<long>::digits);
	 
	printf("char\t\t\t|\t%d\t|\t%d\t|\t%d\t|\t%u\t|\n", sizeof(char), numeric_limits<char>::min(), numeric_limits<char>::max(), numeric_limits<char>::digits);

	printf("float\t\t\t|\t%d\t|  %e |  %e |\t%u\t|\n", sizeof(float), numeric_limits<float>::min(), numeric_limits<float>::max(), numeric_limits<float>::digits);

	printf("double\t\t\t|\t%d\t| %e | %e |\t%u\t|\n", sizeof(double), numeric_limits<double>::min(), numeric_limits<double>::max(), numeric_limits<double>::digits);

	

	system("pause");
	return 0;
}