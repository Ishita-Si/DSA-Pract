1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        int minTime = 0;
5
6        for (int i = 1; i < points.size(); i++) {
7            int dx = abs(points[i][0] - points[i-1][0]);
8            int dy = abs(points[i][1] - points[i-1][1]);
9
10            minTime += max(dx, dy);
11        }
12        return minTime;
13    }
14};