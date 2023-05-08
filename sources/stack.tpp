#ifndef STACK_TPP
#define STACK_TPP

#include "stack.h"

template <class t>
stack<t>::stack() : m_top(nullptr) { }

template <class t>
bool stack<t>::empty() { return m_top == NULL; }

template <class t>
void stack<t>::push(t val) {
	node* newNode = new node;
	newNode->data = val;
	newNode->next = m_top;
	m_top = newNode;
}

template <class t>
void stack<t>::pop()
{
	if(empty())
		std::cout << "Sorry,The stack is Empty...\n";
	else
	{
		node* temp = m_top;
		m_top = m_top->next;
		temp = temp->next = NULL;
		delete temp;
	}
}

template <class t>
t stack<t>::top()
{
	if (empty())
	{
		std::cout << "Sorry,The stack is Empty...\n";
		return 0;
	}
	else
		return m_top->data;
	
}

template <class t>
void stack<t>::print() {
	if (empty())
	{
		std::cout << "Sorry,The stack is Empty...\n";
	}
	else {
		node* cur = m_top;
		std::cout << "[ ";
		while (cur != NULL)
		{
			std::cout << cur->data << " ";
			cur = cur->next;
		}
		std::cout << "]\n";
	}
}

#endif