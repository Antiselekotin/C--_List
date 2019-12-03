#pragma once
#include <string>
#include <fstream>
#include <iostream>

struct char_list
{
		struct elements
		{
			elements* next;
			char ch;
			elements(const char ch, elements* next = nullptr)
			{
				this->ch = ch;
				this->next = next;
			}
		};
		elements* head;
		int size = 0;
	
	void push(char ch);
	int length() { return size; }
	void del(int a);
	void fill_from_array(char arr[], int arr_size);
	void fill_from_file(std::string file_name, int char_quontity);
	void list_print();
	char& operator[](const int index);
	char_list ()
	{
		head = nullptr;
		size = 0;
	}
};
void printer(char_list a);
