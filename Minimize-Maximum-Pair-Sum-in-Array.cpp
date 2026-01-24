1class Solution {
2public:
3    int minPairSum(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        int i = 0, j = nums.size() - 1;
6        int ans = 0;
7        while (i < j) {
8            ans = max(ans, nums[i] + nums[j]);
9            i++;
10            j--;
11        }
12        return ans;
13    }
14};