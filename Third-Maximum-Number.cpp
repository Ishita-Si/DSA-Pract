1class Solution {
2public:
3    int thirdMax(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5
6        int distinct = 1;
7        int n = nums.size();
8
9        for (int i = n - 1; i > 0; i--) {
10            if (nums[i] != nums[i - 1]) {
11                distinct++;
12                if (distinct == 3) {
13                    return nums[i - 1];
14                }
15            }
16        }
17        return nums[n - 1];
18    }
19};