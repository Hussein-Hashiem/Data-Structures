#include <iostream>

using namespace std;

template<class t>
class stack
{
private:
	struct node
	{
		t item;
		node* next;
	};
	node* top;
public:
	stack() :top(NULL) {}
	void push(t newitem)
	{
		node* newitemptr = new node;    // Dynamic memory allocation
		if (newitemptr == NULL)cout << "Stack push can't allocate memory" << endl;
		else {
			newitemptr->item = newitem; // Assign item in newitemptr node by the value entered by the user
			newitemptr->next = top;     // Make next in newitemptr node point to top
			top = newitemptr;           // Make top point top newitem ptr
		}
	}
	bool is_empty() { return top == NULL; }
	void pop()
	{
		if (is_empty()) { cout << "Stack empty on pop" << endl; }
		else {
			node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	void pop(t& stacktop)
	{
		if (is_empty()) { cout << "Stack empty on pop" << endl; }
		else {
			stacktop = top->item;
			node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	void get_top(t& stacktop)
	{
		if (is_empty()) { cout << "Stack empty on get_top" << endl; }
		else stacktop = top->item;
	}
	void print()
	{
		node* temp = top;
		while (temp != NULL) 
		{
			cout << temp->item << endl;
			temp = temp->next;
		}
	}
};

int main()
{
	stack<int>s;
	s.push(7);
	s.push(2);
	s.push(9);
	s.push(15);
	s.push(0);
	s.push(6);
	s.print();
	return 0;
}