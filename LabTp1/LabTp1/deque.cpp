#include"deque.h"
#include<iostream>
Deque::Deque(int num) :size{ 1 }, head{ NULL }, tail{ NULL }
{
	this->PushHead(num);
}
Deque::Deque()
{
	cout << "Вызван конструктор по умолчанию Deque\n";
	head = tail = NULL;
	size = 0;
}
Deque::~Deque()
{
	cout << "Вызван деструктор Deque\n";
	Node* tp;
	while (size != 0)
	{
		tp = tail->next;
		delete tail;
		tail = tp;
		size -= 1;
	}
}

void Deque::ClearVirtual()
{
	cout << this;
}

void Deque::PushBack(int num)
{
	struct Node* temp = new Node;
	size += 1;
	temp->next = tail;
	temp->data = num;
	if (head != NULL)
	{
		if (head->next != NULL)
		{
			head->next = NULL;
		}
		tail = temp;
	}
	else
	{
		head = tail = temp;
	}
}
void Deque::PushHead(int num)
{
	struct Node* temp = new Node;
	size += 1;
	temp->next = NULL;
	temp->data = num;
	if (head != NULL)
	{
		if (tail->next == NULL)
			tail->next = head;
		head->next = temp;
		head = temp;

	}
	else
	{
		head = temp;
		tail = temp;
	}
}
int Deque::PopHead()
{
	int data;
	if (size > 1)
	{
		Node* temp = tail;
		while (temp->next->next != NULL)
			temp = temp->next;
		data = head->data;
		delete head;
		temp->next = NULL;
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
int Deque::PopBack()
{
	int data;
	if (size > 1)
	{
		Node* temp = tail->next;
		data = tail->data;
		delete tail;
		tail = temp;
		size -= 1;
	}
	else
	{
		data = tail->data;
		delete tail;
		head = NULL;
		tail = NULL;
		size -= 1;
	}
	return data;
}
ostream& operator<<(ostream& out, Deque& object)
{
	int i = object.size;
	while (i!=0)
	{
		Deque::Node* temp = object.tail;
		int j = i;
		while (j != 1)
		{
			temp = temp->next;
			--j;
		}
		out << temp->data << " ";
		--i;
	}
	out << endl;
	return out;
}
istream& operator>>(istream& in, Deque& object)
{
	int n,num;
	cout << "Введите значение: ";
	cin >> num;
	bool flag = true;
	while (flag)
	{
		cout << "\nКуда его добавить:\n1-В начало\n2-В конец\n";
		cin >> n;
		switch (n)
		{
		case 1:
			object.PushHead(num);
			flag = false;
			break;
		case 2:
			object.PushBack(num);
			flag = false;
			break;
		default:
			cout << "Неверное значение";
			break;
		}
	}
	return in;
}

ifstream& operator>>(ifstream& fin, Deque& object)
{
	int data,size;
	fin >> size;
	for (int i = 0; i < size; ++i)
	{
		fin >> data;
		object.PushBack(data);
	}
	return fin;
}

ofstream& operator<<(ofstream& fout, Deque& object)
{
	int i = object.size;
	while (i != 0)
	{
		Deque::Node* temp = object.tail;
		int j = i;
		while (j != 1)
		{
			temp = temp->next;
			--j;
		}
		fout << temp->data << endl;
		--i;
	}
	return fout;
}

Deque& Deque:: operator=(const Deque& copy)
{
	int i = copy.size;
	while (i != 0)
	{
		Deque::Node* temp = copy.tail;
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
Deque& Deque:: operator --(int)
{
	int n;
	bool flag = true;
	while (flag)
	{
		cout << "\nОткуда удалить:\n1-Из начала\n2-Из конца\n";
		cin >> n;
		switch (n)
		{
		case 1:
			this->PopHead();
			flag = false;
			break;
		case 2:
			this->PopBack();
			flag = false;
			break;
		default:
			cout << "Неверное значение";
			break;
		}
	}
	return *this;
}
Deque& Deque:: operator-=(int num)
{
	this->PopBack();
	return *this;
}
int Deque::GetSize()
{
	return size;
}