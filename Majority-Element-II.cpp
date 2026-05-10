1class Solution {
2public:
3    vector<int> majorityElement(vector<int>& nums) {
4        vector<int> ans;
5        map<int, int> mp;
6        for (int x : nums) {
7            mp[x]++;
8        }
9        for (auto it : mp) {
10            if (it.second > (nums.size() / 3)) {
11                ans.push_back(it.first);
12            }
13        }
14        return ans;
15    }
16};