
#define STACK_H
#include <iostream>

template <class t>
class queue2
{
private:
	struct node
	{
		t data;
		node* next;
	};
	node* front, * rear;
	int len;
public:
	queue2();
	bool empty();
	void push();
	void pop();
	t first();
	int size();
	void print();
};
