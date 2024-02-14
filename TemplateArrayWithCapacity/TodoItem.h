#pragma once
#include <iostream>
#include <string>
using namespace std;

struct TodoItem
{
	string description;
	bool isCompleted;

	TodoItem(string description, bool isCompleted = false) 
		: description{ description },
		isCompleted{ isCompleted }
	{
		cout << "TodoItem Ctor for " << this << endl;
	}

	TodoItem() : TodoItem{ "" }
	{
	}

	~TodoItem()
	{
		cout << "TodoItem Destructor for " << this << endl;
	}

	friend ostream& operator << (ostream& out, const TodoItem& item)
	{
		out << std::boolalpha;
		out << item.isCompleted << " : " << item.description << endl;

		return out;
	}
};