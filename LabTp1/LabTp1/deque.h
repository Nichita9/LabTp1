#pragma once
#include<fstream>
#include "queue.h"
class Deque:public Queue
{
public:
	struct Node
	{
		int data;
		Node * next;
	};
	Deque();
	Deque(int num);
	~Deque();
	void PushBack(int num) override;
	void PushHead(int num) override;
	int PopHead() override;
	int GetSize();
	int PopBack() override;
	void ClearVirtual() override;
	friend ostream& operator<<(ostream& out, Deque& object);
	friend istream& operator>>(istream& in, Deque& object);
	friend ofstream& operator<<(ofstream& fout, Deque& object);
	friend ifstream& operator>>(ifstream& fin, Deque& object);
	Deque& operator=(const Deque& copy);
	Deque& operator --(int);
	Deque& operator-=(int num);
private:
	Node* tail, * head;
	int size;
};
