#pragma once
#include<fstream>
#include "queue.h"
class Stack :public Queue
{
public:
	struct Node
	{
		int data;
		Node* next;
	};
	Stack();
	Stack(int num);
	~Stack();
	void PushHead(int num) override;
	int PopHead() override;
	int GetSize();
	void ClearVirtual() override;
	friend ostream& operator<<(ostream& out, Stack& object);
	friend istream& operator>>(istream& in, Stack& object);
	friend ofstream& operator<<(ofstream& fout, Stack& object);
	friend ifstream& operator>>(ifstream& fin, Stack& object);
	Stack& operator=(const Stack& copy);
	Stack& operator --(int);
	Stack& operator-=(int num);
private:
	Node* tail, * head;
	int size;
};
