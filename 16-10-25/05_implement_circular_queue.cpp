#include <iostream>
#include <vector>

using namespace std;

class CircularQueue {
private:
    vector<int> arr;
    int capacity;
    int front;
    int rear;

public:
    CircularQueue(int k) : capacity(k + 1), front(0), rear(0) {
        arr.resize(capacity);
    }

    bool isFull() { return (rear + 1) % capacity == front; }
    bool isEmpty() { return front == rear; }

    bool enqueue(int value) {
        if (isFull()) return false;
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    CircularQueue q(3); // Queue size is 3
    q.enqueue(1); 
    q.enqueue(2); 
    q.enqueue(3); 
    cout << "Front: " << q.Front() << endl; // Output: 1
    q.dequeue();
    q.enqueue(4);
    q.dequeue();
    cout << "Front: " << q.Front() << endl; // Output: 3
    return 0;
}