1class Solution {
2public:
3    int minimumDifference(vector<int>& nums, int k) {
4        if (k == 1) return 0;
5
6        sort(nums.begin(), nums.end());
7        int ans = INT_MAX;
8
9        for (int i = 0; i + k - 1 < nums.size(); i++) {
10            ans = min(ans, nums[i + k - 1] - nums[i]);
11        }
12        return ans;
13    }
14};