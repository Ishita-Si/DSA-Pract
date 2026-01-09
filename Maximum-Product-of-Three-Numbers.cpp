1class Solution {
2public:
3    int maximumProduct(vector<int>& nums) {
4        int n = nums.size();
5        if (n < 3) return 0;
6        sort(nums.begin(), nums.end());
7
8        int p1 = nums[n-1] * nums[n-2] * nums[n-3];
9        int p2 = nums[0] * nums[1] * nums[n-1];
10
11        return max(p1, p2);
12    }
13};