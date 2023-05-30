
#ifndef QUEUE_H
#define QUEUE_H

#include "main.h"

namespace udtl {
	/**
	 * @file queue.h
	 * @brief Implementation of a queue data structure.
	 *
	 * This file contains the header for a queue class template in C++.
	 * The queue class is a data structure that stores a collection of elements
	 * in a first-in-first-out (FIFO) order.
	 *
	 * The implementation includes the following member functions:
	 *   - A default constructor that initializes an empty queue.
	 *   - An empty function that returns true if the queue is empty, false otherwise.
	 *   - A push function that adds an element to the back of the queue.
	 *   - A pop function that removes the element at the front of the queue.
	 *   - A front function that returns a reference to the element at the front of the queue.
	 *   - A size function that returns the number of elements in the queue.
	 *   - A back function that returns a reference to the element at the back of the queue.
	 *
	 * The implementation also includes a private node struct that represents a single node
	 * in the queue, with a data member to store the element and a next member to point to
	 * the next node in the queue. The queue class itself has two data members, m_front and
	 * m_rear, which point to the front and rear nodes of the queue, respectively. The m_len
	 * member stores the number of elements in the queue.
	 *
	 * Theimplementation is split across two files, with the class definition in this header file and the actual function implementations in a separate queue.tpp file.
	 * The #include "queue.tpp" statement at the end of the header file is a preprocessor directive that includes the implementation file at the end of this header file.
	 * This technique is sometimes used when implementing class templates to separate the interface (defined in the header file) from the implementation (defined in the implementation file).
	 *
	 * @tparam t The type of elements stored in the queue.
	 */
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
		t back();

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
}

#endif
