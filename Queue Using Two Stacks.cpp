#include <iostream>
#include <stack>
using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> stack1, stack2;

public:
    void enqueue(int item) {
        stack1.push(item);
    }

    int dequeue() {
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int front = stack2.top();
        stack2.pop();
        return front;
    }
};

int main() {
    QueueUsingTwoStacks queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;

    queue.enqueue(4);
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;

    return 0;
}
