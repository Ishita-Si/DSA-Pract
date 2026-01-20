1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4        vector<int> ans(nums.size());
5
6        for (int i = 0; i < nums.size(); i++) {
7            int n = nums[i];
8
9            if (n % 2 == 0) {
10                ans[i] = -1;
11                continue;
12            }
13
14            for (int x = 0; x < n; x++) {
15                if ((x | (x + 1)) == n) {
16                    ans[i] = x;
17                    break;
18                }
19            }
20        }
21        return ans;
22    }
23};