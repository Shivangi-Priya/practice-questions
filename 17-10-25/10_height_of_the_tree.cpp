#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Optimized Solution (Recursive DFS) ---
int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    
    return 1 + max(left_depth, right_depth);
}

// --- Brute-Force/Alternative Solution (Level Order Traversal) ---
// Calculating height using BFS (level order) is less efficient due to queue usage.

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Max Depth/Height: " << maxDepth(root) << endl; // Output: 3
    return 0;
}