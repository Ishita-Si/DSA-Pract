1class Solution {
2public:
3    int minRemoval(vector<int>& nums, int k) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size();
6        int l = 0, maxLen = 0;
7
8        for (int r = 0; r < n; r++) {
9            while ((long long)nums[r] > (long long)k * nums[l]) {
10                l++;
11            }
12            maxLen = max(maxLen, r - l + 1);
13        }
14
15        return n - maxLen;
16    }
17};
18