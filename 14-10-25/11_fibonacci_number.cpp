#include <iostream>
#include <vector>

using namespace std;

int fibOptimized(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibOptimized(n - 1, memo) + fibOptimized(n - 2, memo);
    return memo[n];
}

int fibonacciOptimized(int n) {
    if (n < 0) return -1;
    vector<int> memo(n + 1, -1);
    return fibOptimized(n, memo);
}

int fibonacciBruteForce(int n) {
    if (n <= 1) return n;
    return fibonacciBruteForce(n - 1) + fibonacciBruteForce(n - 2);
}

int main() {
    int n = 10;
    cout << "Optimized Fibonacci(" << n << "): " << fibonacciOptimized(n) << endl;
    cout << "Brute Force Fibonacci(" << n << "): " << fibonacciBruteForce(n) << endl;
    return 0;
}