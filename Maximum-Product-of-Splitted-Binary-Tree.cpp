1class Solution {
2public:
3    long long totalSum = 0;
4    long long bestProduct = 0;
5    static const int MOD = 1e9 + 7;
6
7    long long getTotalSum(TreeNode* root) {
8        if (!root) return 0;
9        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
10    }
11
12    long long dfs(TreeNode* root) {
13        if (!root) return 0;
14
15        long long left = dfs(root->left);
16        long long right = dfs(root->right);
17
18        long long subTreeSum = root->val + left + right;
19
20        long long product = subTreeSum * (totalSum - subTreeSum);
21        bestProduct = max(bestProduct, product);
22
23        return subTreeSum;
24    }
25
26    int maxProduct(TreeNode* root) {
27        totalSum = getTotalSum(root);
28        dfs(root);
29        return bestProduct % MOD;
30    }
31};