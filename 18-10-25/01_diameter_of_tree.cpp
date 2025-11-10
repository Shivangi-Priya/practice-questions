#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Optimized Solution (Post-Order Traversal with Reference) ---
class Solution {
private:
    int height(TreeNode* root, int& diameter) {
        if (root == NULL) return 0;
        
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        
        // Update diameter: max of current diameter or path through root (lh + rh)
        diameter = max(diameter, lh + rh);
        
        // Return height of the current subtree
        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};

// --- Brute-Force Solution (N^2 Approach) ---
int getHeight(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int diameterBruteForce(TreeNode* root) {
    if (root == NULL) return 0;

    int left_diameter = diameterBruteForce(root->left);
    int right_diameter = diameterBruteForce(root->right);
    int diameter_through_root = getHeight(root->left) + getHeight(root->right);

    return max({left_diameter, right_diameter, diameter_through_root});
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    cout << "Diameter (Optimized): " << s.diameterOfBinaryTree(root) << endl; // Output: 3
    cout << "Diameter (Brute Force): " << diameterBruteForce(root) << endl;   // Output: 3
    return 0;
}
