#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Node Structure (Fundamental Implementation)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Tree Implementation/Builder (Breadth-First for Easy Testing)
TreeNode* buildTree(const vector<int>& values) {
    if (values.empty() || values[0] == -1) return NULL;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (i < values.size() && values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Example of a Tree Property Check (Type: Full Binary Tree Check)
bool isFullBinaryTree(TreeNode* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    if (root->left != NULL && root->right != NULL) {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }
    return false;
}

int main() {
    // Example Tree: [1, 2, 3, 4, 5, -1, 6] (-1 represents NULL)
    vector<int> values = {1, 2, 3, 4, 5, -1, 6};
    TreeNode* root = buildTree(values);

    cout << "Root value: " << root->val << endl; 
    cout << "Is Full Binary Tree: " << isFullBinaryTree(root) << endl; // Output: 0 (false)
    return 0;
}