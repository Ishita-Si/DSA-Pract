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
14    int maxLevelSum(TreeNode* root) {
15        int maxSum = INT_MIN;
16        int resultLevel = 0;
17
18        queue <TreeNode*> que;
19        que.push(root);
20        int currLevel = 1;
21        while(!que.empty()){
22            int n = que.size();
23            int sum = 0;
24            while(n--){
25                TreeNode* temp = que.front();
26                que.pop();
27                sum += temp -> val;
28                if(temp->left){
29                    que.push(temp->left);
30                }
31                if(temp->right){
32                    que.push(temp->right);
33                }
34            }
35            if(sum>maxSum){
36                maxSum = sum;
37                resultLevel = currLevel;
38            }
39            currLevel++;
40        }
41        return resultLevel;
42    }
43};