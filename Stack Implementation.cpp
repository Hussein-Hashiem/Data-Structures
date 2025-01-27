#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;
template <class t>
class stack
{
private:
	int top;
	t items[MAX_SIZE];
public:
	stack() :top(-1) {}
	bool is_empty() { return top < 0; }
	void push(t element)
	{
		if (top >= MAX_SIZE - 1) cout << "Stack is full." << endl;
		else
		{
			top++;
			items[top] = element;
		}
	}
	void pop()
	{
		if (is_empty()) cout << "Stack is empty" << endl;
		else top--;
	}
	void pop(t &element)
	{
		if (is_empty()) cout << "Stack is empty" << endl;
		else 
		{
			element = items[top];
			top--;
		}
	}
	void get_top()
	{
		if (is_empty()) cout << "Stack is empty" << endl;
		else cout << items[top] << endl;
	}
	void get_top(t& element)
	{
		if (is_empty()) cout << "Stack is empty" << endl;
		else
		{
			element = items[top];
			cout << element << endl;
		}
	}
	void print()
	{
		for (int i = top; i >= 0; i--) { cout << items[i] << endl; }
	}
};

int main()
{
	stack<char> s;
	s.push('H');
	s.push('U');
	s.push('S');
	s.push('N');
	s.print();
	return 0;
}