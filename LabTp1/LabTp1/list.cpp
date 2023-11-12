#include"List.h"
#include<iostream>
List::List(int num) :size{ 1 }, head{ NULL }, tail{ NULL }
{
	this->PushHead(num);
}
List::List()
{
	cout << "Вызван конструктор по умолчанию Stack\n";
	head = tail = NULL;
	size = 0;
}
List::~List()
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

void List::ClearVirtual()
{
	cout << this;
}

void List:: Push(int num)
{
	if(size==0)
	{
		this->PushHead(num);
		return;
	}
	Node* new_element = new Node;
	Node* temp = head,*ptr=head;
	new_element->data = num;
	new_element->next = NULL;
	cout << "Куда вставить элемент?\n" << *this<<endl;
	int n;
	while (1)
	{
		cin >> n;
		if (n > size)
			cout << "Некорректное значение\n";
		else
			break;
	}
	if (n == 0)
	{
		this->PushHead(num);
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		ptr = temp;
		temp = temp->next;
	}
	if (ptr->next != NULL)
	{
		new_element->next = temp;
		ptr->next = new_element;
		size += 1;
		return;
	}
	ptr->next = new_element;
	size += 1;

}

void List::Pop()
{
	Node* temp = head;
	Node* deleted;
	cout << "Какой элемент удалить?\n" << *this << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		temp = temp->next;
	}
	deleted = temp->next;
	temp->next = temp->next->next;
	size -= 1;
	delete[]deleted;
}

void List::PushHead(int num)
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

int List::PopHead()
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

ostream& operator<<(ostream& out, List& object)
{
	List::Node* temp = object.head;
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
istream& operator>>(istream& in, List& object)
{
	int num;
	cout << "Введите значение: ";
	cin >> num;
	object.Push(num);
	return in;
}

ifstream& operator>>(ifstream& fin, List& object)
{
	int data, size;
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

ofstream& operator<<(ofstream& fout, List& object)
{
	List::Node* temp = object.head;
	while (1)
	{
		fout << temp->data << endl;
		if (temp->next == NULL)
			break;
		temp = temp->next;

	}
	return fout;
}

List& List:: operator=(const List& copy)
{
	int i = copy.size;
	while (i != 0)
	{
		List::Node* temp = copy.tail;
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
List& List:: operator --(int)
{
	this->Pop();
	return *this;
}
List& List:: operator-=(int num)
{
	this->PopHead();
	return *this;
}
int List::GetSize()
{
	return size;
}