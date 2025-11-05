#include <iostream>
#include <vector>
#include <list>

using namespace std;

// --- Optimized Solution (Boundary Traversal) ---
vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty() || matrix[0].empty()) return result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // 1. Traverse Right
        for (int j = left; j <= right; ++j) {
            result.push_back(matrix[top][j]);
        }
        top++;

        // 2. Traverse Down
        if (top <= bottom) {
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;
        }

        // 3. Traverse Left
        if (top <= bottom && left <= right) {
            for (int j = right; j >= left; --j) {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        // 4. Traverse Up
        if (top <= bottom && left <= right) {
            for (int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return result;
}



int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result = spiralOrder(matrix);
    cout << "Spiral Traversal: ";
    for (int x : result) cout << x << " "; 
    cout << endl; 
    return 0;
}