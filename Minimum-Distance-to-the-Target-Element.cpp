1class Solution {
2public:
3    int getMinDistance(vector<int>& nums, int target, int start) {
4        int ans = INT_MAX;
5            for (int i = 0; i < nums.size();i++) {
6                if (nums[i] == target) {
7                    int val = abs(i - start);
8                    ans = min(ans, val);
9                }
10            }
11        return ans;
12    }
13};