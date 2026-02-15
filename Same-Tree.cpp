1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
10 * right(right) {}
11 * };
12 */
13class Solution {
14public:
15    bool isSameTree(TreeNode* p, TreeNode* q) {
16        if (p == NULL && q == NULL)
17            return true;
18
19        if (p == NULL || q == NULL)
20            return false;
21
22        if (p->val != q->val)
23            return false;
24
25        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
26    }
27};