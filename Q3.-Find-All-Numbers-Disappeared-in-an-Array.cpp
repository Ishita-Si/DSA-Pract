1class Solution {
2public:
3    vector<int> findDisappearedNumbers(vector<int>& nums) {
4        int n = nums.size();
5
6        for (int i = 0; i < n; i++) {
7            int idx = abs(nums[i]) - 1;
8            if (nums[idx] > 0)
9                nums[idx] = -nums[idx];
10        }
11
12        vector<int> ans;
13        for (int i = 0; i < n; i++) {
14            if (nums[i] > 0)
15                ans.push_back(i + 1);
16        }
17
18        return ans;
19    }
20};