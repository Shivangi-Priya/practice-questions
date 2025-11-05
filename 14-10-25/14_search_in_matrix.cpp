#include <iostream>
#include <vector>

using namespace std;


pair<int, int> searchMatrixOptimized(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return {-1, -1};

    int rows = matrix.size();
    int cols = matrix[0].size();
    
 
    int row = 0;
    int col = cols - 1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return {row, col};
        } else if (matrix[row][col] > target) {
           
            col--;
        } else {
           
            row++;
        }
    }

    return {-1, -1}; 
}


pair<int, int> searchMatrixBruteForce(const vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == target) {
                return {i, j};
            }
        }
    }
    return {-1, -1}; 
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target = 12;

    pair<int, int> resultOpt = searchMatrixOptimized(matrix, target);
    cout << "Optimized Search Index for " << target << ": (" << resultOpt.first << ", " << resultOpt.second << ")" << endl;

    int target2 = 20;
    pair<int, int> resultBrute = searchMatrixBruteForce(matrix, target2);
    cout << "Brute Force Search Index for " << target2 << ": (" << resultBrute.first << ", " << resultBrute.second << ")" << endl;

    return 0;
}