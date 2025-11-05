#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr, int m) {
    int start = m + 1;        
    int end = arr.size() - 1;

   
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int t;
    cin >> t;  
    while (t--) {
        int n, m;
        cin >> n; 
        vector<int> arr(n);

        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cin >> m;
       
        reverseArray(arr, m);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
