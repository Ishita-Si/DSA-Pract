1class Solution {
2public:
3    vector<vector<int>> merge(vector<vector<int>>& intervals) {
4        sort(intervals.begin(), intervals.end());
5
6        vector<vector<int>> ans;
7        ans.push_back(intervals[0]);
8
9        for (int i = 1; i < intervals.size(); i++) {
10            if (intervals[i][0] <= ans.back()[1]) {
11                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
12            } else {
13                ans.push_back(intervals[i]);
14            }
15        }
16
17        return ans;
18    }
19};