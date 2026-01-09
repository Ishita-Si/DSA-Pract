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
14    pair<int, TreeNode*> dfs(TreeNode* root) {
15        if (!root) return {0, nullptr};
16
17        auto left = dfs(root->left);
18        auto right = dfs(root->right);
19
20        if (left.first > right.first) {
21            return {left.first + 1, left.second};
22        } 
23        if (right.first > left.first) {
24            return {right.first + 1, right.second};
25        }
26
27        return {left.first + 1, root};
28    }
29
30    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
31        return dfs(root).second;
32    }
33};