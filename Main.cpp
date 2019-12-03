#include "Funcs.h"


int main ()
{
	char_list a;
	int question;
	std::cout << "Input \"1\" to fill list from file"
		<< std::endl << "Input \"2\" to fill list from array" << std::endl;
	std::cin >> question;
	switch (question)
	{
	case 1:
		std::cout << "Input \"1\" to create your file"
		<< std::endl << "Input \"2\" to use already created file" << std::endl;
		int question1;
		std::cin >> question1;
		switch (question1)
		{
		case 1:
		{
			std::cout << "Input file name (example: C:\\windows\\f.txt (use double back slash))" << std::endl;
			std::string str;
			std::cin >> str;
			std::ofstream fout(str);
			std::cout << "Input your text" << std::endl;
			std::string text;
			std::cin >> text;
			const int text_size = text.size();
			fout << text;
			fout.close();
			a.fill_from_file(str, text_size);
			printer(a);
		}
		break;
		case 2:
		{
			std::cout << "Input file name (example: C:\\windows\\f.txt (use double back slash))" << std::endl;
			std::string str;
			std::cin >> str;
			std::cout << "Input quontity of chars you want to push in list" << std::endl;
			int char_quo;
			std::cin >> char_quo;
			a.fill_from_file(str, char_quo);
			printer(a);
		}
			break;
		}
		break;
	case 2:
		{
		std::cout << "Input array length" << std::endl;
		int arr_length;
		std::cin >> arr_length;
		char* arr = new char[arr_length];
			for (int i = 0; i < arr_length;i++)
			{
				std::cout << "input next element" << std::endl;
				std::cin >> arr[i];
			}
			a.fill_from_array(arr, arr_length);
			delete[] arr;
			printer(a);
		}
		break;
	}
	system("pause");
}

