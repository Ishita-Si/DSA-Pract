1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int l = 0, r = 0;
5        int maxLen = 0, len = 0;
6        int zeros = 0;
7
8        while (r < nums.size()) {
9            if (nums[r] == 0) {
10                zeros++;
11            }
12            while (zeros > k) {
13                if (nums[l] == 0) {
14                    zeros--;
15                }
16                l++; 
17            }
18            if (zeros <= k) {
19                    len = r - l + 1;
20                    maxLen = max(len, maxLen);
21                }
22                r++;
23        }
24        return maxLen;
25    }
26};