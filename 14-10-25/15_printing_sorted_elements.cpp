#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> printSortedOptimized(const vector<vector<int>>& matrix) {
    vector<int> flat_array;
    if (matrix.empty()) return flat_array;

    
    for (const auto& row : matrix) {
        flat_array.insert(flat_array.end(), row.begin(), row.end());
    }

    sort(flat_array.begin(), flat_array.end());
    
    return flat_array;
}



int main() {
    vector<vector<int>> matrix = {
        {10, 5, 20},
        {2, 15, 8},
        {30, 1, 9}
    };

    vector<int> result = printSortedOptimized(matrix);
    cout << "Sorted Elements: ";
    for (int x : result) cout << x << " "; 
    cout << endl;

    return 0;
}