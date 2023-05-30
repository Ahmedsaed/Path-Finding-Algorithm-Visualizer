#ifndef STACK_H
#define STACK_H

#include "main.h"

namespace udtl {
	/**
	 * @file stack.h
	 * @brief Implementation of a stack data structure.
	 *
	 * This file contains the header for a stack class template in C++.
	 * The stack class is a data structure that stores a collection of elements
	 * in a last-in-first-out (LIFO) order.
	 *
	 * The implementation includes the following member functions:
	 *   - A default constructor that initializes an empty stack.
	 *   - An empty function that returns true if the stack is empty, false otherwise.
	 *   - A push function that adds an element to the top of the stack.
	 *   - A pop function that removes the element at the top of the stack.
	 *   - A top function that returns a reference to the element at the top of the stack.
	 *   - A print function that prints the elements of the stack to the console.
	 *
	 * The implementation also includes a private node struct that represents a single node
	 * in the stack, with a data member to store the element and a next member to point to
	 * the next node in the stack. The stack class itself has a single data member, m_top,
	 * which points to the top node of the stack.
	 *
	 * The implementation is split across two files, with the class definition in this header file and the actual function implementations in a separate stack.tpp file.
	 * The #include "stack.tpp" statement at the end ofthe header file is a preprocessor directive that includes the implementation file at the end of this header file.
	 * This technique is sometimes used when implementing class templates to separate the interface (defined in the header file) from the implementation (defined in the implementation file).
	 *
	 * @tparam t The type of elements stored in the stack.
	 */
	template <class t>
	class stack
	{
	public:
		stack();
		bool empty();
		void push(t val);
		void pop();
		t& top();
		void print();

	private:
		struct node {
			t data;
			node* next;
		};
		node* m_top;
	};

	#include "stack.tpp"
}

#endif
