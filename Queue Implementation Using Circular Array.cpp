#include <iostream>
#include <cassert>

using namespace std;

template <class t>
class arrayQueueType
{
private:
	int rear;
	int front;
	int length;
	t* arr;
	int MAX_LENGTH;
public:
	arrayQueueType(int size) :front(0), rear(MAX_LENGTH - 1), length(0)
	{
		if (size <= 0) MAX_LENGTH = 100;
		else MAX_LENGTH = size;
		arr = new t[MAX_LENGTH];
	}
	bool is_empty() { return !length; }
	bool is_full() { return length == MAX_LENGTH; }
	void enqueue(t new_element)
	{
		if (is_full())cout << "Queue is full can't enqueue..." << endl;
		else
		{
			rear = (rear + 1) % MAX_LENGTH;
			arr[rear] = new_element;
			length++;
		}
	}
	void dequeue()
	{
		if (is_empty())cout << "Queue is empty can't dequeue..." << endl;
		else front = (front + 1) % MAX_LENGTH, length--;
	}
	int get_front()
	{
		assert(!is_empty());
		return arr[front];
	}
	int get_rear()
	{
		assert(!is_empty());
		return arr[rear];
	}
	void print()
	{
		if (is_empty()) cout << "Queue is empty." << endl;
		else
		{
			for (int i = front; i != rear; i = (i + 1) % MAX_LENGTH) cout << arr[i] << ' ';
			cout << arr[rear] << endl;
		}
	}
	int search(t element)
	{
		int pos = -1;
		if (is_empty()) cout << "Queue is empty." << endl;
		else
		{
			for (int i = front; i != rear; i = (i + 1) % MAX_LENGTH)
			{
				if (arr[i] == element)
				{
					pos = i;
					break;
				}
			}
			if (pos == -1 && arr[rear] == element) pos = rear;
		}
		return pos;
	}
};

int main()
{
	arrayQueueType<int> q1(10);
	q1.enqueue(6);
	q1.enqueue(9);
	q1.enqueue(10);
	q1.enqueue(6);
	q1.print();
	return 0;
}
