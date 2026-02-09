1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    bool isBalanced(TreeNode* root) {
15        return checkHeight(root) != -1;
16    }
17
18private:
19    int checkHeight(TreeNode* node) {
20        if (node == nullptr) return 0;
21
22        // Recursively get the height of the left subtree
23        int leftHeight = checkHeight(node->left);
24        if (leftHeight == -1) return -1; // Left side is already unbalanced
25
26        // Recursively get the height of the right subtree
27        int rightHeight = checkHeight(node->right);
28        if (rightHeight == -1) return -1; // Right side is already unbalanced
29
30        // If the current node is unbalanced, return -1
31        if (std::abs(leftHeight - rightHeight) > 1) {
32            return -1;
33        }
34
35        // Otherwise, return the actual height of this node
36        return 1 + std::max(leftHeight, rightHeight);
37    }
38};