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
14    TreeNode* balanceBST(TreeNode* root) {
15        vector<int> sortedNodes;
16        // Step 1: Flatten the tree into a sorted vector
17        inorder(root, sortedNodes);
18        
19        // Step 2: Build the balanced tree from the sorted vector
20        return buildBalancedBST(sortedNodes, 0, sortedNodes.size() - 1);
21    }
22
23private:
24    void inorder(TreeNode* node, vector<int>& nodes) {
25        if (!node) return;
26        inorder(node->left, nodes);
27        nodes.push_back(node->val);
28        inorder(node->right, nodes);
29    }
30
31    TreeNode* buildBalancedBST(const vector<int>& nodes, int start, int end) {
32        if (start > end) return nullptr;
33
34        // Pick the middle element to ensure balance
35        int mid = start + (end - start) / 2;
36        TreeNode* newNode = new TreeNode(nodes[mid]);
37
38        // Recursively build subtrees
39        newNode->left = buildBalancedBST(nodes, start, mid - 1);
40        newNode->right = buildBalancedBST(nodes, mid + 1, end);
41
42        return newNode;
43    }
44};