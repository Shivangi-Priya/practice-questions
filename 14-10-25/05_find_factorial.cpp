

#include <iostream>

using namespace std;


long long factorialOptimized(int n) {
    if (n < 0) return 0; // Handle error case
    if (n == 0 || n == 1) return 1;

    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long long factorialBruteForce(int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive step
    return (long long)n * factorialBruteForce(n - 1);
}


int main() {
    int n = 10;
    cout << "Optimized Factorial of " << n << ": " << factorialOptimized(n) << endl;
    cout << "Brute Force Factorial of " << n << ": " << factorialBruteForce(n) << endl;

    return 0;
}