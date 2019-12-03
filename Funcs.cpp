#include "Funcs.h"

void char_list::push(char ch)
{
	if (head == nullptr)
	{
		head = new elements(ch);
	}
	else
	{
		elements* current = this->head;

		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new elements(ch);
	}
	size++;
}

void char_list::del(int a)
{
	elements* del_elem = this->head;
	int counter = 1;
	while (counter != a)
	{
		del_elem = del_elem->next;
		counter++;
	}
	elements* help = del_elem->next;
	del_elem->next = del_elem->next->next;
	delete help;
	size--;
}

void char_list::fill_from_array(char arr[], int arr_size)
{
	char* ptr = &arr[arr_size-1];
	char* stop = arr;
	for (ptr; ptr >= stop; ptr--)
	{
		push(*ptr);
	}
}

void char_list::fill_from_file(const std::string file_name,const int char_quontity)
{
	std::ifstream fin(file_name);
	char stream_carry;
	for(int a = 0; a < char_quontity; a++)
	{
		fin >> stream_carry;
		push(stream_carry);
	}
	fin.close();
}

void char_list::list_print()
{
	elements* outer = head;
	for (int i = 0; i < size; i++)
	{
		std::cout << outer->ch;
		outer = outer->next;
	}
}

char& char_list::operator[](const int index)
{
	elements* current = this->head; 
	int count = 0;
	while (current != nullptr)
	{
		if(count == index)
		{
			return current->ch;
		}
		count++;
		current = current->next;
	}
}
void printer(char_list a)
{
	std::cout << "Do you wanna print your list? (y/n)" << std::endl;
	char ans;
	std::cin >> ans;
	if (ans == 'y')
	{
		a.list_print();
	}
}
