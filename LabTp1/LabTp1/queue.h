#pragma once
#include "keeper.h"
class Queue
{
public:
	Queue();
	virtual ~Queue();
	virtual void ClearVirtual() = 0;
	virtual void PushHead(int num) {};
	virtual void PushBack(int num) {};
	virtual int PopHead() { return 0; };
	virtual int PopBack() { return 0; };
};