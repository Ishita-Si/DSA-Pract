1class Solution {
2public:
3    vector<int> findErrorNums(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5
6        int duplicate = -1;
7        int missing = -1;
8
9        for (int i = 0; i < nums.size() - 1; i++) {
10            if (nums[i] == nums[i + 1]) {
11                duplicate = nums[i];
12            }
13            if (nums[i + 1] - nums[i] == 2) {
14                missing = nums[i] + 1;
15            }
16        }
17
18        if (nums[0] != 1) missing = 1;
19        if (nums.back() != nums.size()) missing = nums.size();
20
21        return {duplicate, missing};
22    }
23};
24