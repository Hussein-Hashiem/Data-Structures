#include <iostream>

using namespace std;

template<class t>
class doubly_linked_list
{
private:
	struct Node
	{
		t item;
		Node* nxt;
		Node* prv;
	};
	Node* first;
	Node* last;
	int length;
public:
	doubly_linked_list() {
		length = 0;
		first = last = NULL;
	}
	bool is_empty() { return !length; }
	void insertFirst(t val) {
		Node* newnode = new Node;
		newnode->item = val;
		if (!length) {
			first = last = newnode;
			newnode->nxt = newnode->prv = NULL;
		}
		else {
			newnode->nxt = first;
			newnode->prv = NULL;
			first->prv = newnode;
			first = newnode;
		}
		length++;
	}
	void insertLast(t val) {
		Node* newnode = new Node;
		newnode->item = val;
		if (!length) {
			first = last = newnode;
			newnode->nxt = newnode->prv = NULL;
		}
		else {
			newnode->prv = last;
			newnode->nxt = NULL;
			last->nxt = newnode;
			last = newnode;
		}
		length++;
	}
	void insertatPosition(int pos, t val) {
		if (pos<0 || pos>length) cout << "Out of range." << endl;
		else if (pos == 0) insertFirst(val);
		else if (pos == length) insertLast(val);
		else {
			Node* newnode = new Node;
			newnode->item = val;
			Node* curr = first;
			for (int i = 1; i < pos; i++) curr = curr->nxt;
			newnode->nxt = curr->nxt;
			newnode->prv = curr;
			curr->nxt->prv = newnode;
			curr->nxt = newnode;
			length++;
		}
	}
	void popFirst() {
		if (!length) cout << "List is empty." << endl;
		else if (length == 1) {
			delete first;
			first = last = NULL;
			length--;
		}
		else {
			Node* curr = first;
			first = first->nxt;
			first->prv = NULL;
			delete curr;
			length--;
		}
	}
	void popBack() {
		if (!length) cout << "List is empty." << endl;
		else if (length == 1) {
			delete first;
			first = last = NULL;
			length--;
		}
		else {
			Node* curr = last;
			last = last->prv;
			last->nxt = NULL;
			delete curr;
			length--;
		}
	}
	void pop(t val) {
		if (!length) cout << "List is empty." << endl;
		else if (first->item == val) popFirst();
		else if (last->item == val) popBack();
		else {
			Node* curr = first;
			while (curr != NULL) {
				if (curr->item == val) break;
				curr = curr->nxt;
			}
			if (curr == NULL) cout << "The item is not there." << endl;
			else {
				curr->prv->nxt = curr->nxt;
				curr->nxt->prv = curr->prv;
				delete curr;
				length--;
			}
		}
	}
	void print() {
		Node* curr = first;
		while (curr != NULL) {
			cout << curr->item<<' ';
			curr = curr->nxt;
		}
		cout << endl;
	}
	void printReverse() {
		Node* curr = last;
		while (curr != NULL) {
			cout << curr->item<<' ';
			curr = curr->prv;
		}
		cout << endl;
	}
};

int main()
{
	doubly_linked_list<char>d;
	d.insertFirst('d');
	d.insertFirst('f');
	d.insertFirst('t');
	d.insertLast('e');
	d.insertLast('i');
	d.insertatPosition(4, 'Y');
	d.print();
	return 0;
}
