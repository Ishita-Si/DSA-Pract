1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        unordered_map<int, vector<int>> mp;
5    
6    for (int i = 0; i < nums.size(); i++) {
7        mp[nums[i]].push_back(i);
8    }
9    
10    int ans = INT_MAX;
11
12    for (auto &it : mp) {
13        vector<int>& v = it.second;
14        
15        if (v.size() < 3) continue;
16
17        for (int i = 0; i + 2 < v.size(); i++) {
18            int dist = 2 * (v[i + 2] - v[i]);
19            ans = min(ans, dist);
20        }
21    }
22    
23    return (ans == INT_MAX ? -1 : ans);
24    }
25};