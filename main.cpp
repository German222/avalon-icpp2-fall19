#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Book
{
	static const int BUFFER_SIZE = 20;
	int Id;
	char Title[BUFFER_SIZE];
	char Author[BUFFER_SIZE];
	float Price;
	int Quantity;
};

void swap(Book& book1, Book& book2)
{
	Book temp;
	temp = book2;
	book2 = book1;
	book1 = temp;
}
string concatenate(char* first, char* second)
{
	string strLeft(first);
	string strRight(second);

	return strLeft + strRight;
}

int main()
{
	ofstream fout("books.bin", istream::out | istream::binary);
	fout.close();

	int choice = 0;

	while (choice != 6)
	{
		cout << endl << "#1: Write in a book." << endl << "#2: Redact using Id." << endl << "#3: Reserch the book." << endl << "#4: Watch the list." << endl << "#5: Show stat." << endl << "#6: Close." << endl;
		cin >> choice;
		ifstream fin("books.bin", istream::in | istream::binary);
		fin.seekg(0, ios_base::end);
		int size = fin.tellg();
		int count = size / sizeof(Book);
		fin.seekg(0, ios_base::beg);

		Book* books1 = new Book[count];
		fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
		fin.close();
		if (choice == 1)
		{
			fout.open("books.bin", istream::app);
			cout << "Write Id, Title, Author, Price and  Quantity" << endl;
			Book book;
			cin >> book.Id >> book.Title >> book.Author >> book.Price >> book.Quantity;

			fout.write(reinterpret_cast<char*>(&book), sizeof(Book));
			fout.close();

			fin.open("books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
			fin.close();

			for (int i = 0; i < count; ++i)
			{
				cout << books1[i].Id << " " << books1[i].Title << " " << books1[i].Author << " " << books1[i].Price << " " << books1[i].Quantity << endl;
			}

		}
		if (choice == 2)
		{
			fin.open("books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
			fin.close();
			int Id, k;
			cin >> Id;
			Book* ptr = nullptr;
			for (int i = 0; i < count; ++i)
			{
				if (Id == books1[i].Id)
				{
					ptr = &books1[i];
					k = i;
					break;
				}
			}

			if (ptr == nullptr)
			{
				cout << "student with Id " << Id << " not found" << endl;
			}
			else
			{
				cin >> ptr->Title >> ptr->Author >> ptr->Price >> ptr->Quantity;

				fout.open("books.bin", istream::out | istream::binary);
				fout.seekp((k) * sizeof(Book), ios_base::beg);
				fout.write(reinterpret_cast<char*>(ptr), sizeof(Book));
				fout.close();
				fin.open("books.bin", ios_base::in | ios_base::binary);
				fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
				fin.close();

				for (int i = 0; i < count; ++i)
				{
					cout << books1[i].Id << " " << books1[i].Title << " " << books1[i].Author << " " << books1[i].Price << " " << books1[i].Quantity << endl;
				}
			}
		}
		if (choice == 3)
		{
			fin.open("books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
			fin.close();
			string name;
			cin >> name;

			Book* ptr = nullptr;
			for (int i = 0; i < count; ++i)
			{
				string temp(books1[i].Title);
				if (name == temp)
				{
					ptr = &books1[i];
					break;
				}
			}

			if (ptr == nullptr)
			{
				cout << "student with name " << name << " not found" << endl;
			}
			else
			{
				cout << ptr->Id << " " << ptr->Title << " " << ptr->Author << " " << ptr->Price << " " << ptr->Quantity << endl;
			}
		}
		if (choice == 4)
		{
			fin.open("books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
			fin.close();

			for (int k = 0; k < count; ++k)
			{
				for (int i = 0; i < count - 1; ++i)
				{
					if (concatenate(books1[i].Title, books1[i].Author) > concatenate(books1[i + 1].Title, books1[i + 1].Author))
					{
						swap(books1[i], books1[i + 1]);
					}
				}
			}
			for (int i = 0; i < count; ++i)
			{
				cout << books1[i].Id << " " << books1[i].Title << " " << books1[i].Author << " " << books1[i].Price << " " << books1[i].Quantity << endl;
			}
		}
		if (choice == 5)
		{
			fin.open("books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
			fin.close();
			int sum_price = 0;
			int sum_quantity = 0;

			for (int i = 0; i < count; ++i)
			{
				sum_price += books1[i].Price;
				sum_quantity += books1[i].Quantity;
			}
			cout << "Summary price of books: " << sum_price << ", summary quantity: " << sum_quantity << std::endl;
		}
		if (choice == 6)
		{
			return 0;
		}
	}
}