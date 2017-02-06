// ReverseLinkList.cpp : Defines the entry point for the console application.
//

#include<iostream>

using namespace std;

class LinkLsit
{
public:
	struct node
	{
		char value;
		node *next;
	};
	node *head;
	LinkLsit();
	void initalValues(char items[], int size);
	~LinkLsit();
	void push(char value);
	void display();
	bool empty();
	void reverseLsit();
private:

};



LinkLsit::LinkLsit()
{
}

void LinkLsit::initalValues(char items[], int size)
{
	for (int i = 0; i < size; i++)
	{
		push(items[i]);
	}
}

LinkLsit::~LinkLsit()
{
}
void LinkLsit::push(char value)
{
	node *p = new node();
	p->value = value;
	p->next = NULL;

	if (head == NULL)
	{
		head = p;
	}
	else
	{
		node *temp;
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = p;
	}
}
void LinkLsit::display()
{
	if (empty())
	{
		cout << "Linked List is Empty" << endl;
	}
	else
	{
		node *temp = head;
		cout << "linklist Values : ";
		while (temp != NULL)
		{
			cout << temp->value << ", ";
			temp = temp->next;
		}
		cout << "" << endl;
		if (temp == NULL)
		{
			delete temp;
		}
	}
}
bool LinkLsit::empty()
{
	if (head == NULL)
		return true;
	else
		return false;
}
void LinkLsit::reverseLsit()
{
	node* cursor = NULL;
	node* temp;
	while (head != NULL)
	{
		temp = head->next;
		head->next = cursor;
		cursor = head;
		head = temp;
	}
	head = cursor;
}
int main()
{
	LinkLsit test;

	const int size = 5;
	char items[size] = {'a','b','c','d','e' };
	test.initalValues(items, size);

	test.display();
	test.reverseLsit();
	cout << "Reversed" << endl;
	test.display();
	return 0;
}

