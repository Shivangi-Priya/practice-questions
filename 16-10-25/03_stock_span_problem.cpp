#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> calculateSpan(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> s; // Stores indices

    for (int i = 0; i < n; ++i) {
        // Pop elements from stack while their prices are less than or equal to the current price
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }

        // Calculate span: if stack is empty, span is i+1, else it's i - s.top()
        span[i] = s.empty() ? (i + 1) : (i - s.top());

        // Push current index onto the stack
        s.push(i);
    }
    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = calculateSpan(prices);
    cout << "Stock Spans: ";
    for (int s : span) cout << s << " "; 
    cout << endl;
    return 0;
}