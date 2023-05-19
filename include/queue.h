
#ifndef QUEUE_H
#define QUEUE_H

#include "main.h"

template <class t>
class queue
{
public:
	queue();
	bool empty();
	void push(t val);
	void pop();
	t front();
	int size();

private:
	struct node
	{
		t data;
		node* next;
	};

	node* m_front, * m_rear;
	int m_len;
};

#include "queue.tpp"

#endif