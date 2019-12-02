#include <iostream>
#include <string>
#include <fstream>
#include "Funcs.h"
using namespace std;

void printer (char_list a);
int main ()
{
	char_list a;
	int question;
	cout << "Input \"1\" to fill list from file"
		<< endl << "Input \"2\" to fill list from array" << endl;
	cin >> question;
	switch (question)
	{
	case 1:
		cout << "Input \"1\" to create your file"
		<< endl << "Input \"2\" to use already created file" << endl;
		int question1;
		cin >> question1;
		switch (question1)
		{
		case 1:
		{
			cout << "Input file name (example: C:\\windows\\f.txt (use double back slash))" << endl;
			string str;
			cin >> str;
			ofstream fout(str);
			cout << "Input your text" << endl;
			string text;
			cin >> text;
			const int text_size = text.size();
			fout << text;
			fout.close();
			a.fill_from_file(str, text_size);
			printer(a);
		}
		break;
		case 2:
		{
			cout << "Input file name (example: C:\\windows\\f.txt (use double back slash))" << endl;
			string str;
			cin >> str;
			cout << "Input quontity of chars you want to push in list" << endl;
			int char_quo;
			cin >> char_quo;
			a.fill_from_file(str, char_quo);
			printer(a);
		}
			break;
		}
		break;
	case 2:
		{
		cout << "Input array length" << endl;
		int arr_length;
		cin >> arr_length;
		char* arr = new char[arr_length];
			for (int i = 0; i < arr_length;i++)
			{
				cout << "input next element" << endl;
				cin >> arr[i];
			}
			a.fill_from_array(arr, arr_length);
			delete[] arr;
			printer(a);
		}
		break;
	}
	system("pause");
}
void printer(char_list a)
{
	cout << "Do you wanna print your list? (y/n)" << endl;
	char ans;
	cin >> ans;
	if (ans == 'y')
	{
		a.list_print();
	}
}
