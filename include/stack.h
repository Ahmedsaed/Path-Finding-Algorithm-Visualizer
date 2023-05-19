#ifndef STACK_H
#define STACK_H

#include "main.h"

template <class t>
class stack
{
public:
	stack();
	bool empty();
	void push(t val);
	void pop();
	t top();
	void print();

private:
	struct node {
		t data;
		node* next;
	};
	node* m_top;
};

#include "stack.tpp"

#endif
