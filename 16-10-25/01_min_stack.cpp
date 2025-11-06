#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    void push(int val) {
        dataStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }
        dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Min: " << minStack.getMin() << endl; // Output: -3
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;    // Output: 0
    cout << "Min: " << minStack.getMin() << endl; // Output: -2
    return 0;
}
