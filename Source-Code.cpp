#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
void clrscr()
{
	system("cls");
}
void insertionSort(fstream &user) {
	int i, j, f=0;
	string key, sorting[10];
	user.open("user.txt", ios::in);
	while (!user.eof())
	{
		getline(user, sorting[f], '\n');
		f++;
	}
	user.close();
	for (i = 1; i < f; i++)
	{
		key = sorting[i];
		j = i - 1;
		while (j >= 0 && sorting[j] > key)
		{
			sorting[j + 1] = sorting[j];
			--j;
		}
		sorting[j + 1] = key;
	}
	user.open("user.txt", ios::out);
	for (int d = 0; d < f; d++)
	{
		if (d < f - 1)
		{
			user << sorting[d] << endl;
		}
		else
			user << sorting[d];
	}
	user.close();
}
void book_update(string book_data[][2], fstream &books, int j)
{
	books.open("books.txt", ios::out);
	for (int a = 0; a < j; a++)
	{
		books << book_data[a][0] << ':' << book_data[a][1] << endl;
	}
	books.close();
}
void library_update(string library_data[][5], fstream& library)
{
	library.open("library.txt", ios::out);
	for (int x = 0; x < 3; x++)
	{
		string str;
		str = library_data[x][0] + " " + library_data[x][1] + ",";
		for (int j = 2; j < 5; j++)
		{
			if (library_data[x][j] == "")
			{
				continue;
			}
			else if (library_data[x][j + 1] == "" || j == 4)
			{
				str += library_data[x][j];
			}
			else
			{
				str += library_data[x][j] + ":";
			}
		}
		library << str << endl;
	}
	library.close();
}
void insertion_sort(string arr[])
{
	int i, j;
	string key;
	for (i = 3; i < 5; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 2 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void helper(fstream &user,string user_data[][3],int &i)
{
	user.open("user.txt", ios::in);
	i = 0;
	while (!user.eof()) {
		for (int k = 0; k < 3; k++)
		{
			if (k < 2)
			{
				getline(user, user_data[i][k], ' ');
			}
			else
			{
				getline(user, user_data[i][k], '\n');
			}
		}
		i++;
	}
	user.close();
}
void user_input(fstream& user, fstream& library, string user_data[][3], int i)
{
	user.open("user.txt", ios::app);
	library.open("library.txt", ios::app);
	if (!user)
	{
		cout << "Flie cannot be opened!" << endl;
	}
	else
	{
		bool found = false;
		string firstName, lastName, email, middleName;
		cout << "Enter your following details: " << endl;
		cout << "First Name: " << endl;
		cin >> firstName;
		cout << "Last Name: " << endl;
		cin >> lastName;
		cout << "Email: " << endl;
		cin >> email;
		for (int j = 0; j < i; j++)
		{
			if (user_data[j][0] == firstName)
			{
				cout << "User already exists!" << endl;
				system("PAUSE");
				found = true;
			}
		}
		if (!found)
		{
			user << endl << firstName << ' ' << lastName << ' ' << email;
			library << endl << firstName << ' ' << lastName << ',';
			cout << "Successfully added!" << endl;
			system("PAUSE");
		}
		user.close();
		library.close();
	}
}
void add_books(string book_data[][2], int j)
{
	ofstream books{ "books.txt", ios::app };
	string books_name;
	bool found = false;
	cout << "Enter the name of the book: ";
	cin.ignore();
	getline(cin, books_name);
	for (int i = 0; i < j; i++)
	{
		if (book_data[i][0] == books_name)
		{
			found = true;
			cout << "Book already exists!" << endl;
			system("PAUSE");
		}
	}
	if (!found)
	{
		books << endl << books_name << ':' << "Available";
		cout << "Book added successfully!";
		system("PAUSE");
	}
	books.close();
	
}
void book_output(string book_data[][2], int j)
{
	for (int i = 0; i < j; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cout << book_data[i][k] << ' ';
		}
		cout << endl;
	}
	system("PAUSE");
}
void user_output(fstream &user, int j, string user_data[][3])
{
	for (int i = 0; i < j; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << user_data[i][j] << ' ';
		}
		cout << endl;
	}
	system("PAUSE");
}
void delete_name(fstream& user, string user_data[][3], int a)
{
	string delete_first_name, last_name;
	bool found = false;
	int similiar = 0;
	cout << "Enter the First name of the user which have to be deleted: ";
	cin >> delete_first_name;
	cout << "Enter the Last name of the user which have to be deleted: ";
	cin >> last_name;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (user_data[i][j] == delete_first_name && user_data[i][j+1] == last_name)
			{
				similiar++;
				found = true;
				for (int k = i; k < a; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						user_data[k][l] = user_data[k + 1][l];
					}
				}
				user.open("user.txt", ios::out);
				cout << "Deleted successfully" << endl;
				system("PAUSE");
				for (int k = 0; k < a - 1; k++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (j < 2)
						{
							user << user_data[k][j] << ' ';
						}
						else
						{
							if (k == a-2)
								user << user_data[k][j];
							else
								user << user_data[k][j] << endl;
						}
					}
				}
				user.close();
				break;
			}
		}
	}
	if (!found)
	{
		cout << "User not found!" << endl;
		system("PAUSE");
	}
}
void search_name(fstream &user, string user_data[][3], int i, fstream &library, string library_data[][5])
{
	library.open("library.txt", ios::app || ios::in);
	bool found = false;
	string searchname, last_name, str, name, firstname, lastname;
	int commas = 0, j = 0;;
;
	cout << "Enter name to search: ";
	cin >> searchname;
	cout << "Enter last name: ";
	cin >> last_name;
	for (int j = 0; j < i; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (user_data[j][k] == searchname && user_data[j][k + 1] == last_name)
			{
				found = true;
				for (int l = 0; l < 3; l++)
				{
					cout << user_data[j][l] << endl;
				}
				cout << endl;
			}
		}
	}
	for (int j = 0; j < i; j++)
	{
		for (int l = 2; l < 5; l++)
		{
			if (library_data[j][0] == searchname && library_data[j][1] == last_name && library_data[j][2] != "")
			{
				cout << library_data[j][l] << endl;
			}
			else if (library_data[j][0] == searchname && library_data[j][1] == last_name)
			{
				cout << "No book issued!" << endl;
				break;
			}
		}
	}
	system("PAUSE");
	user.close();
	if (!found)
	{
		cout << "User not found!" << endl;
		system("PAUSE");
	}
}
void loan_book(fstream& books, fstream& library, string user_data[][3], int i, string book_data[][2], string library_data[][5], int p)
{
	bool user_found = false, book_available = false, space_available = false, found = false;
	string first_name, last_name, book_name;
	cout << "Enter First name: ";
	cin >> first_name;
	cout << "Enter last_name: ";
	cin >> last_name;
	cout << "Enter book title: ";
	cin >> book_name;
	for (int j = 0; j < i; j++)
	{
		for (int x = 0; x < 2; x++)
		{
			if (user_data[j][x] == first_name && user_data[j][x+1] == last_name)
			{
				user_found = true;
			}
		}
		for (int x = 0; x < 5; x++)
		{
			if (library_data[j][x] == "" && library_data[j][0] == first_name && library_data[j][1] == last_name)
			{
				space_available = true;
			}
		}
		for (int x = 0; x < p; x++)
		{
			for (int o = 0; o < 1; o++)
			{
				if (book_data[j][x] == book_name && book_data[j][x + 1] == "Available")
				{
					book_available = true;
				}
			}
		}
		if (user_found = true && book_available == true && space_available == true)
		{
			cout << "Loaned successfully!";

			found = true;
			break;
		}
		
	}
	if (!found)
	{
		cout << "Cannot loan book" << endl;
		system("PAUSE");

	}
	
	if (found)
	{
		for (int f = 0; f < p; f++)
		{
			for (int x = 0; x < 1; x++)
			{
				if (book_data[f][x] == book_name)
				{
					book_data[f][x + 1] = "Borrowed";
					break;
				}
			}
		}
		for (int j = 0; j < i; j++)
		{

			for (int x = 0; x < 5; x++)
			{
				{
					if (library_data[j][0] == first_name && library_data[j][1] == last_name && library_data[j][x] == "")
					{
						library_data[j][x] = book_name;
						break;
					}
				}
			}
		}
		book_update(book_data, books, p);
		library_update(library_data, library);
		system("PAUSE");
	}
}
void return_book(fstream &user, fstream &library, fstream &books, int i, string library_data[][5], string book_data[][2], string user_data[][3], int j)
{
	bool user_found = false, book_available = false, book_loaned = false, found = false;
	string first_name, last_name, book_name;
	cout << "Enter First name: ";
	cin >> first_name;
	cout << "Enter last_name: ";
	cin >> last_name;
	cout << "Enter book title: ";
	cin >> book_name;
	for (int q = 0; q < i; q++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (user_data[q][k] == first_name && user_data[q][k + 1] == last_name)
			{
				user_found = true;
			}
		}
		for (int x = 0; x < 5; x++)
		{

			if (library_data[q][x] == book_name && library_data[q][0] == first_name && library_data[q][1] == last_name)
			{
				book_loaned = true;
			}
		}
		
		for (int x = 0; x < 10; x++)
		{
			for (int o = 0; o < 1; o++)
			{
				if (book_data[o][x] == book_name && book_data[0][x + 1] == "Borrowed")
				{
					book_available = true;
				}
			}
		}
			
		if (user_found = true && book_available == true && book_loaned == true)
		{
			found = true;
			cout << "Successfully returned!" << endl;

			break;
		}
	}
	if (!user_found && book_loaned && book_available)
		cout << "User not found!";
	else if (!book_loaned && user_found && book_available)
		cout << "You have not loaned the book!";

	if (found)
	{
		for (int f = 0; f < 10; f++)
		{
			for (int x = 0; x < 1; x++)
			{
				if (book_data[f][x] == book_name)
				{
					book_data[f][x + 1] = "Available";
					break;
				}
			}
		}
		for (int k = 0; k < i; k++)
		{

			for (int x = 0; x < 5; x++)
			{
				{
					if (library_data[k][0] == first_name && library_data[k][1] == last_name && library_data[k][x] == book_name)
					{
						library_data[k][x] = "";
						break;
					}
				}
			}
		}
		book_update(book_data, books, j);
		library_update(library_data, library);
		system("PAUSE");
	}
}
void menu()
{
	int x = -1;
	do
	{
		fstream user, books, library;
		string sorting[10], user_data[10][3], book_data[50][2], librarydata[10], name, library_data[10][5], firstname, lastname;
		int f = 0, i = 0, j = 0, commas = 0, n = 0;
		helper(user, user_data, i);
		books.open("books.txt", ios::in);
		while (!books.eof())
		{
			string str;
			getline(books, str, '\n');
			int pos = str.find(":");
			book_data[j][0] = str.substr(0, pos);
			book_data[j][1] = str.substr(pos + 1, str.length());
			j++;
		}
		books.close();
		library.open("library.txt", ios::app || ios::in);
		while (!library.eof())
		{
			getline(library, librarydata[n], '\n');
			n++;
		}
		for (int k = 0; k < n; k++)
		{
			string str;
			str = librarydata[k];
			int pos = str.find(",");
			name = str.substr(0, pos);
			int space = name.find(" ");
			firstname = name.substr(0, space);
			lastname = name.substr(space + 1, name.length() - space);
			str = str.substr(pos + 1, str.length());
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ':')
					commas++;
			}
			library_data[k][0] = name.substr(0, space);
			library_data[k][1] = name.substr(space + 1, name.length() - space);
			for (int i = 2; i < commas + 3; i++)
			{
				int pos = str.find(":");
				library_data[k][i] = str.substr(0, pos);
				str = str.substr(pos + 1, str.length());
			}
			commas = 0;
		}
		library.close();
		cout << "1. Add a new user to the system." << endl;
		cout << "2. Delete an Existing user from the system." << endl;
		cout << "3. Search a user." << endl;
		cout << "4. Loan a book." << endl;
		cout << "5. Return a book." << endl;
		cout << "6. Display the list of users." << endl;
		cout << "7. Display all the books." << endl;
		cout << "8. Add a book." << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{	
			user_input(user, library, user_data, i);
			insertionSort(user);
			break;
		}
		case 2:
		{
			delete_name(user, user_data, i);
			break;
		}
		case 3:
		{
			search_name(user, user_data, i, library, library_data);
			break;
		}
		case 4:
		{
			loan_book(books, library, user_data, i, book_data, library_data, j);
			break;
		}
		case 5:
		{
			return_book(user, library, books, i, library_data, book_data, user_data, j);
			break;
		}
		case 6:
		{
			insertionSort(user);
			helper(user, user_data, i);
			user_output(user, i, user_data);
			break;
		}
		case 7:
		{
			book_output(book_data, j);
			break;
		}
		case 8:
		{
			add_books(book_data, j);
			break;
		}
		case 0:
			break;
		default:
			cout << "Invalid choice, please try again!" << endl;
		}
		clrscr();
	} while (x != 0);
}
int main()
{
	menu();
}