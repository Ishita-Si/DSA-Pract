1class Solution {
2public:
3    int maxCount(int m, int n, vector<vector<int>>& ops) {
4        int minRow = m, minCol = n;
5
6        for (auto& op : ops) {
7            minRow = min(minRow, op[0]);
8            minCol = min(minCol, op[1]);
9        }
10        return minRow * minCol;
11    }
12};