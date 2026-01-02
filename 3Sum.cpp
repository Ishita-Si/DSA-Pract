1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        vector<vector<int>> ans;
5        int n = nums.size();
6        sort(nums.begin(), nums.end());
7
8        for (int i = 0; i < n; i++) {
9
10            if (i > 0 && nums[i] == nums[i - 1]) continue;
11
12            int left = i + 1;
13            int right = n - 1;
14
15            while (left < right) {
16                int sum = nums[i] + nums[left] + nums[right];
17
18                if (sum == 0) {
19                    ans.push_back({nums[i], nums[left], nums[right]});
20
21                    while (left < right && nums[left] == nums[left + 1]) left++;
22                    while (left < right && nums[right] == nums[right - 1]) right--;
23
24                    left++;
25                    right--;
26                }
27                else if (sum < 0) {
28                    left++;
29                }
30                else {
31                    right--;
32                }
33            }
34        }
35        return ans;
36    }
37};
38