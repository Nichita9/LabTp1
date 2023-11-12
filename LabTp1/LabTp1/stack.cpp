#include"stack.h"
#include<iostream>
Stack::Stack(int num) :size{ 1 }, head{ NULL }, tail{ NULL }
{
	this->PushHead(num);
}
Stack::Stack()
{
	cout << "Вызван конструктор по умолчанию Stack\n";
	head = tail = NULL;
	size = 0;
}
Stack::~Stack()
{
	cout << "Вызван деструктор Stack\n";
	Node* tp;
	while (size != 0)
	{
		tp = head->next;
		delete head;
		head = tp;
		size -= 1;
	}
}

void Stack::ClearVirtual()
{
	cout << this;
}

void Stack::PushHead(int num)
{
	struct Node* temp = new Node;
	size += 1;
	temp->next = head;
	temp->data = num;
	if (head != NULL)
	{
		if (head->next == NULL)
		{
			head->next = tail;
			tail->next = NULL;
		}
		head = temp;

	}
	else
	{
		head = temp;
		tail = temp;
	}
}
int Stack::PopHead()
{
	int data;
	if (size > 1)
	{
		Node* temp = head->next;
		data = head->data;
		delete head;
		head = temp;
		size -= 1;
	}
	else
	{
		data = head->data;
		delete head;
		head = NULL;
		tail = NULL;
		size -= 1;
	}
	return data;
}

ostream& operator<<(ostream& out, Stack& object)
{
		Stack::Node* temp = object.head;
		while (1)
		{
			out << temp->data << " ";
			if (temp->next == NULL)
				break;
			temp = temp->next;

		}
	out << endl;
	return out;
}
istream& operator>>(istream& in, Stack& object)
{
	int num;
	cout << "Введите значение: ";
	cin >> num;
	object.PushHead(num);
	return in;
}

ifstream& operator>>(ifstream& fin, Stack& object)
{
	int data,size;
	fin >> size;
	int* datas = new int[size];
	for (int i = 0; i < size; ++i)
		fin >> datas[i];
	for (int i = size; i > 0; --i)
		object.PushHead(datas[i - 1]);
	//check
	delete[]datas;
	return fin;
}

ofstream& operator<<(ofstream& fout, Stack& object)
{
	Stack::Node* temp = object.head;
	while (1)
	{
		fout << temp->data << endl;
		if (temp->next == NULL)
			break;
		temp = temp->next;

	}
	return fout;
}

Stack& Stack:: operator=(const Stack& copy)
{
	int i = copy.size;
	while (i != 0)
	{
		Stack::Node* temp = copy.tail;
		int j = i;
		while (j != 1)
		{
			temp = temp->next;
			--j;
		}
		this->PushHead(temp->data);
		--i;
	}
	return *this;
}
Stack& Stack:: operator --(int)
{
	this->PopHead();
	return *this;
}
Stack& Stack:: operator-=(int num)
{
	this->PopHead();
	return *this;
}
int Stack::GetSize()
{
	return size;
}