1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        int n = nums.size();
5    for (int i = 0; i < n; ++i) {
6        for (int j = i + 1; j < n; ++j) {
7            if (nums[i] + nums[j] == target) {
8                return {i, j};
9            }
10        }
11    }  
12    return {};
13    }
14};