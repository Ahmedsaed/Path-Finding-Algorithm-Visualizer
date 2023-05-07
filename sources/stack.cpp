#include <iostream>
using namespace std;
template <class t>
class Stack
{
	struct node {
		t data;
		node* next;
	};
	node* top;
public:
	Stack() { top = NULL; }
	bool Empty() { return top == NULL; }
	void push(t val) {
		node* newNode = new node;
		newNode->data = val;
		newNode->next = top;
		top = newNode;

	}
	void pop()
	{
		if(Empty())
			cout << "Sorry,The Stack is Empty...\n";
		else
		{
			node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	t Top()
	{
		if (Empty())
			cout << "Sorry,The Stack is Empty...\n";
		else
			return top->data;
	}
	void print() {
		if (Empty())
		{
			cout << "Sorry,The Stack is Empty...\n";
		}
		else {
			node* cur = top;
			cout << "[ ";
			while (cur != NULL)
			{
				cout << cur->data << " ";
				cur = cur->next;
			}
			cout << "]\n";
		}
	}
};
int main()
{
	Stack <int > s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	cout << s.Top() << endl;
	s.pop();
	s.push(50);
	s.print();
	

	
	
}
