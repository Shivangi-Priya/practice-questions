

#include <iostream>

using namespace std;


void printDecreasing(int n) {
    if (n == 0) return;
    cout << n << " "; 
    printDecreasing(n - 1);
}


void printIncreasing(int n) {
    if (n == 0) return;
    printIncreasing(n - 1);
    cout << n << " "; 
}


void printDecInc(int n) {
    if (n == 0) return;
    cout << n << " ";         
    printDecInc(n - 1);
    if (n > 1) {             
        cout << n << " ";   
    }
}

void printIncreasingIterative(int n) {
    for (int i = 1; i <= n; ++i) {
        cout << i << " ";
    }
}


int main() {
    int n = 5;

    cout << "Decreasing (Optimized): ";
    printDecreasing(n);
    cout << endl;

    cout << "Increasing (Optimized): ";
    printIncreasing(n);
    cout << endl;

    cout << "Dec-Inc (Optimized): ";
    printDecInc(n);
    cout << endl;

    cout << "Increasing (Iterative/Brute Force): ";
    printIncreasingIterative(n);
    cout << endl;

    return 0;
}