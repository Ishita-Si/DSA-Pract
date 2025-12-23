1class Solution {
2public:
3    vector<int> shuffle(vector<int>& nums, int n) {
4        vector<int> ans(2 * n);
5        for (int i = 0; i < n; i++) {
6            ans[2*i]     = nums[i];
7            ans[2*i + 1] = nums[i + n];
8        }
9        return ans;
10    }
11};
12