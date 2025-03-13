#include <iostream>

using namespace std;

template <class t>
class linked_list
{
private:
	struct Node
	{
		t item;
		Node* nxt;
	};
	Node* first;
	Node* last;
	int length;
public:
	linked_list() {
		first = last = NULL;
		length = 0;
	}
	bool isempty() { return length == 0; }
	void insertFirst(t val) {
		Node* newnode = new Node;
		newnode->item = val;
		if (!length) {
			first = last = newnode;
			newnode->nxt = NULL;
		}
		else {
			newnode->nxt = first;
			first = newnode;
		}
		length++;
	}
	void insertLast(t val) {
		Node* newnode = new Node;
		newnode->item = val;
		if (!length) {
			first = last = newnode;
			newnode->nxt = NULL;
		}
		else {
			last->nxt = newnode;
			newnode->nxt = NULL;
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
			Node* curr = first;
			for (int i = 1; i < pos; i++) curr = curr->nxt;
			newnode->item = val;
			newnode->nxt = curr->nxt;
			curr->nxt = newnode;
			length++;
		}
	}
	void popFirst(){
		if (!length) cout << "Empty list can't remove." << endl;
		else if (length == 1) {
			delete first;
			first = last = NULL;
			length--;
		}
		else {
			Node* curr = first;
			first = first->nxt;
			delete curr;
			length--;
		}
	}
	void popBack() {
		if (!length) cout << "Empty list can't remove." << endl;
		else if (length == 1) {
			delete first;
			first = last = NULL;
			length--;
		}
		else {
			Node* prev = first, * curr = first->nxt;
			while (curr != last) {
				prev = curr;
				curr = curr->nxt;
			}
			delete curr;
			prev->nxt = NULL;
			last = prev;
			length--;
		}
	}
	void pop(t val) {
		if (!length) cout << "Empty list can't remove." << endl;
		else if (first->item == val) popFirst();
		else if (last->item == val) popBack();
		else {
			Node* prev = first, * curr = first->nxt;
			while (curr != NULL) {
				if (curr->item == val) break;
				prev = curr;
				curr = curr->nxt;
			}
			if (curr == NULL) cout << "The item is not there." << endl;
			else {
				prev->nxt = curr->nxt;
				delete curr;
				length--;
			}
		}
	}
	void reverse() {
		Node* prev = NULL, * curr = first, * next = curr->nxt;
		while (next != NULL) {
			next = curr->nxt;
			curr->nxt = prev;
			prev = curr;
			curr = next;
		}
		first = prev;
	}
	void search(t val) {
		Node* curr = first;
		int pos = 0;
		while (curr != NULL) {
			if (curr->item == val) {
				cout << "Item is found at pos " << pos << '.' << endl;
				return;
			}
			curr = curr->nxt;
			pos++;
		}
		cout << "Item is not found." << endl;
	}
	void print() {
		Node* curr = first;
		while (curr != NULL) {
			cout << curr->item << ' ';
			curr = curr->nxt;
		}
		cout << endl;
	}
};

int main()
{
	linked_list <char>l;
	l.insertLast('d');
	l.insertLast('e');
	l.insertLast('y');
	l.insertLast('i');
	l.reverse();
	l.print();
	l.search('i');
	l.search('a');
	return 0;
}
