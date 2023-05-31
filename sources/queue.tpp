#ifndef QUEUE_TPP
#define QUEUE_TPP

#include "queue.h"

template <class t>
udtl::queue<t>::queue()
{
	m_front = m_rear = NULL;
	m_len = 0;
}

template <class t>
udtl::queue<t>::~queue()
{
	while (!empty())
		pop();

	m_front = m_rear = NULL;
	m_len = 0;
}

template <class t>
bool udtl::queue<t>::empty()
{
	return m_front == NULL;
}

template <class t>
void udtl::queue<t>::push(t val)
{
	node *newNode = new node;
	newNode->data = val;
	newNode->next = NULL;
	if (empty())
	{
		m_front = m_rear = newNode;
	}
	else
	{
		m_rear->next = newNode;
		m_rear = newNode;
		m_rear->next = NULL;
	}
	m_len++;
}

template <class t>
void udtl::queue<t>::pop()
{
	if (empty())
		throw std::out_of_range("The queue is Empty...\n");
	else
	{
		node *temp = m_front;
		m_front = m_front->next;
		delete temp;
		m_len--;

		if (empty())
			m_rear = NULL;
	}
}

template <class t>
t udtl::queue<t>::front()
{
	if (empty())
	{
		std::cout << "Sorry, The queue is Empty...\n";
		return 0;
	}
	else
		return m_front->data;
}
template<class t>
t udtl::queue<t>::back()
{

if (empty())
	{
		std::cout << "Sorry, The queue is Empty...\n";
		return 0;
	}
	else
	return m_rear->data;
}
template <class t>
int udtl::queue<t>::size()
{
	return m_len;
}

#endif
