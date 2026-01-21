1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans;
6        ans.reserve(n);
7        
8        for (int val : nums) {
9            if (val == 2) {
10                ans.push_back(-1);
11            } else if (val % 2 == 0) {
12                ans.push_back(-1);
13            } else {
14                long long temp = (long long)val + 1;
15                long long diff = (temp & -temp) >> 1;
16                ans.push_back(val - diff);
17            }
18        }
19        return ans;
20    }
21};