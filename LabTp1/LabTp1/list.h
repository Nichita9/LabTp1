#pragma once
#include<fstream>
#include "queue.h"
class List :public Queue
{
public:
	struct Node
	{
		int data;
		Node* next;
	};
	List();
	List(int num);
	~List();
	void Push(int num);
	void Pop();
	void PushHead(int num) override;
	int PopHead() override;
	int GetSize();
	void ClearVirtual() override;
	friend ostream& operator<<(ostream& out, List& object);
	friend istream& operator>>(istream& in, List& object);
	friend ofstream& operator<<(ofstream& fout, List& object);
	friend ifstream& operator>>(ifstream& fin, List& object);
	List& operator=(const List& copy);
	List& operator --(int);
	List& operator-=(int num);
private:
	Node* tail, * head;
	int size;
};
