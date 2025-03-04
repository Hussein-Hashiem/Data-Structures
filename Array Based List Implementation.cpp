#include <iostream>

using namespace std;

class arraylist
{
private:
	int* list;
	int length;
	int MAX_SIZE;
public:
	arraylist(int size = 100) {
		if (size < 0) MAX_SIZE = 100;
		else MAX_SIZE = size;
		length = 0;
		list = new int[MAX_SIZE];
	}
	~arraylist() { delete[] list; }
	bool is_empty() { return length == 0; }
	bool is_full() { return length == MAX_SIZE; }
	int list_size() { return length; }
	int max_list_size() { return MAX_SIZE; }
	void print() {
		for (int i = 0; i < length; i++) cout << list[i] << ' ';
		cout << endl;
	}
	void insert(int loc, int val) {
		if (is_full()) cout << "Array is full." << endl;
		else if (loc < 0 || loc >= length) cout << "Out of range." << endl;
		else {
			for (int i = length; i > loc; i--) list[i] = list[i - 1];
			list[loc] = val;
			length++;
		}
	}
	void insert_at_end(int val) {
		if (is_full()) cout << "Array is full." << endl;
		else list[length++] = val;
	}
	void update(int loc, int val) {
		if (loc < 0 || loc >= length) cout << "Out of range." << endl;
		else list[loc] = val;
	}
	void clear() { length = 0; }
	int search(int val) {
		for (int i = 0; i < length; i++)
			if (list[i] == val) return i;
		return -1;
	}
	void insert_no_dublicate(int val)
	{
		if (is_full()) cout << "Array is full." << endl;
		else if (search(val) == -1) list[length++] = val;
		else cout << "No duplicates are allowed." << endl;
	}
	void removeAT(int loc) {
		if (loc < 0 || loc >= length) cout << "Out of range." << endl;
		else {
			for (int i = loc; i < length - 1; i++) list[i] = list[i + 1];
			length--;
		}
	}
	void remove(int val) {
		int loc = search(val);
		if (loc == -1) cout << "The item to be deleted is not in the list." << endl;
		else removeAT(loc);
	}
};

int main()
{
	arraylist a(5);
	a.insert_at_end(4);
	a.insert_at_end(1);
	a.insert_at_end(2);
	a.remove(1);
	a.update(0, 9);
	a.print();
	return 0;
}
