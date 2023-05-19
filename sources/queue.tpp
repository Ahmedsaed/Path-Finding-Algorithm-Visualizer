
#include <iostream>
#include <queue.h>
template<class t>
 inline queue2<t>::queue2()
{
	front = rear = NULL;
	len = 0;
}

 template<class t>
 inline bool queue2<t>::empty()
 {
	 return front == NULL;
 }

 template<class t>
 inline void queue2<t>::push()
 {
	 node* newNode = new node;
	 newNode->data = val;
	 newNode->next = NULL;
	 if (empty())
	 {
		 front = rear = newNode;
	 }
	 else {
		 rear->next = newNode;
		 rear = newNode;
		 rear->next = NULL;
	 }
	 len++;
 }

 template<class t>
 inline void queue2<t>::pop()
 {
	 if (empty())
		 cout << "Sorry, The queue is Empty...\n";
	 else {
		 node* temp = front;
		 front = front->next;
		 temp = temp->next = NULL;
		 delete temp;
		 len--;
	 }
 }

 template<class t>
 inline t queue2<t>::first()
 {
	 if (empty())
		 cout << "Sorry, The queue is Empty...\n";
	 else
		 return  front->data;
 }

 template<class t>
 inline int queue2<t>::size()
 {
	 return len;
 }

 template<class t>
 inline void queue2<t>::print()
 {
	 if (empty())
		 cout << "Sorry, The queue is Empty...\n";
	 else
	 {
		 node* cur = front;
		 while (cur != NULL)
		 {
			 cout << cur->data << " ";
			 cur = cur->next;
		 }
	 }
 }
