#include <iostream>

using namespace std;

template<class t>
class linked_queue
{
private:
	struct Node
	{
		t item;
		Node* nxt;
	};
	int length;
	Node* frontptr, * rearptr;
public:
	linked_queue() :frontptr(NULL), rearptr(NULL), length(0) {}
	bool is_empty() { return length == 0; }
	void enqueue(t newitem) {
		Node* newitemptr = new Node;
		newitemptr->item = newitem;
		newitemptr->nxt = NULL;
		if (!length) frontptr = rearptr = newitemptr;
		else
		{
			rearptr->nxt = newitemptr;
			rearptr = newitemptr;
		}
		length++;
	}
	void dequeue() {
		if (is_empty())cout << "Queue is empty." << endl;
		else if (length == 1) {
			delete frontptr;
			rearptr = NULL;
			length = 0;
		}
		else {
			Node* curr = frontptr;
			frontptr = frontptr->nxt;
			delete curr;
			length--;
		}
	}
	int front() {
		if (is_empty())cout << "Queue is empty." << endl;
		else return frontptr->item;
	}
	int rear() {
		if (is_empty())cout << "Queue is empty." << endl;
		else return rearptr->item;
	}
	void clear() {
		Node* curr;
		while (frontptr != NULL) {
			curr = frontptr;
			frontptr = frontptr->nxt;
			delete curr;
		}
		rearptr = NULL;
		length = 0;
	}
	void print() {
		Node* curr = frontptr;
		while (curr != NULL)
		{
			cout << curr->item << ' ';
			curr = curr->nxt;
		}
		cout << endl;
	}
	void search(t i) {
		Node* curr = frontptr;
		bool ch = 0;
		while (curr != NULL)
		{
			if (curr->item == i) {
				ch = 1;
				cout << "The item " << i << " found." << endl;
				break;
			}
			curr = curr->nxt;
		}
		if (!ch)cout << "The item " << i << " not found." << endl;
	}
};

int main()
{
	linked_queue<int> q;
	q.enqueue(4);
	q.enqueue(6);
	q.enqueue(1);
	q.enqueue(98);
	q.enqueue(9);
	q.enqueue(0);
	q.print();
	return 0;
}
