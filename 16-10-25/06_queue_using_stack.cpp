#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStack {
private:
    stack<int> input;
    stack<int> output;

    void transfer() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    void push(int x) {
        input.push(x);
    }

    int pop() {
        transfer();
        int item = output.top();
        output.pop();
        return item;
    }

    int peek() {
        transfer();
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    QueueUsingStack q;
    q.push(1);
    q.push(2);
    cout << "Peek: " << q.peek() << endl; // Output: 1
    cout << "Pop: " << q.pop() << endl;  // Output: 1
    q.push(3);
    cout << "Pop: " << q.pop() << endl;  // Output: 2
    return 0;
}