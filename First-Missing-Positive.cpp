1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        int n = nums.size();
5
6        for (int i = 0; i < n; i++) {
7            if (nums[i] <= 0 || nums[i] > n)
8                nums[i] = n + 1;
9        }
10
11        for (int i = 0; i < n; i++) {
12            int x = abs(nums[i]);
13            if (x >= 1 && x <= n) {
14                nums[x - 1] = -abs(nums[x - 1]);
15            }
16        }
17
18        for (int i = 0; i < n; i++) {
19            if (nums[i] > 0)
20                return i + 1;
21        }
22
23        return n + 1;
24    }
25};
26