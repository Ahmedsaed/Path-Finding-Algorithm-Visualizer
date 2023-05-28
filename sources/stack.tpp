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
	if(!empty())
	{
		node* temp = m_top;
		m_top = m_top->next;
		temp = temp->next = NULL;
		delete temp;
	}
}

template <class t>
t& stack<t>::top()
{
	if (empty())
		throw std::runtime_error("Sorry, the stack is empty...");
	else
		return m_top->data;
}

#endif
