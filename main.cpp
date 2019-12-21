#include <iostream>
#include "CharString.hpp"

using namespace std;
using namespace ext;

int main()
{
	CharString* s1 = new CharString{ 'H' };
	CharString* s2 = new CharString{ 'E' };
	CharString* s3 = new CharString{ 'L' };

	CharString* ptr = nullptr;
	ptr = s1;
	s1->nextSymbol = s2;
	s2->nextSymbol = s3;

	print(ptr);
	cout << endl;
	append(ptr, 'L');
	print(ptr);
	cout << endl;

	append(ptr, 'O');
	append(ptr, ' ');
	append(ptr, 'W');
	append(ptr, 'O');
	append(ptr, 'R');
	append(ptr, 'L');
	append(ptr, 'D');


	int i;
	cin >> i;
	char Answer2 = characterAt(ptr, i);
	cout << Answer2 << endl;;
	int fir, sec;
	cin >> fir >> sec;

	removeChars(ptr, fir, sec);
	print(ptr);

}