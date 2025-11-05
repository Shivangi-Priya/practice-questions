#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    for (int x : arr) cout << x << " ";

    bubbleSort(arr);

    cout << "\nSorted Array (Bubble Sort): ";
    for (int x : arr) cout << x << " ";

    cout << "\n\nTime Complexity: Best O(n), Average O(n^2), Worst O(n^2)";
    cout << "\nSpace Complexity: O(1)\n";

    return 0;
}
