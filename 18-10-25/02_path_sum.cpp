#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Optimized Solution (Recursive DFS) ---
bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == NULL) return false;

    // Check if it's a leaf node
    if (root->left == NULL && root->right == NULL) {
        return targetSum == root->val;
    }

    // Recursively check left and right subtrees
    int remainingSum = targetSum - root->val;
    return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
}

// --- Brute-Force/Alternative Solution (Iterative BFS/DFS with stack/queue) ---
// An iterative DFS solution using a stack is an alternative, avoiding recursion stack depth issues, 
// but the recursive solution is simpler and generally preferred unless list depth is extreme.

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->right = new TreeNode(2);
    root->left->left->left = new TreeNode(7);

    int target1 = 22; // Path 5->4->11->2
    int target2 = 18; // Path 5->4->11->7 (doesn't exist)
    
    cout << "Has Path Sum " << target1 << " (Optimized): " << hasPathSum(root, target1) << endl; // Output: 1 (true)
    cout << "Has Path Sum " << target2 << " (Optimized): " << hasPathSum(root, target2) << endl; // Output: 0 (false)
    return 0;
}