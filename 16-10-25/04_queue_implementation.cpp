#include <iostream>
#include <vector>

using namespace std;

class ArrayQueue {
private:
    vector<int> arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    ArrayQueue(int cap) : capacity(cap), front(0), rear(cap - 1), size(0) {
        arr.resize(capacity);
    }

    bool isFull() { return size == capacity; }
    bool isEmpty() { return size == 0; }

    void enqueue(int item) {
        if (isFull()) return;
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    ArrayQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.getFront() << endl; // Output: 10
    cout << "Dequeued: " << q.dequeue() << endl;      // Output: 10
    q.enqueue(40);
    cout << "Front element: " << q.getFront() << endl; // Output: 20
    return 0;
}