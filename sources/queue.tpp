#ifndef QUEUE_TPP
#define QUEUE_TPP

#include "queue.h"

template <class t>
queue<t>::queue()
{
	m_front = m_rear = NULL;
	m_len = 0;
}

template <class t>
bool queue<t>::empty()
{
	return m_front == NULL;
}

template <class t>
void queue<t>::push(t val)
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
void queue<t>::pop()
{
	if (empty())
		std::cout << "Sorry, The queue is Empty...\n";
	else
	{
		node *temp = m_front;
		m_front = m_front->next;
		temp = temp->next = NULL;
		delete temp;
		m_len--;
	}
}

template <class t>
t queue<t>::front()
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
t queue<t>::back()
{
	return m_rear->data;
}
template <class t>
int queue<t>::size()
{
	return m_len;
}

#endif
