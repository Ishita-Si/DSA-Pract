1class Solution {
2public:
3    long long largestSquareArea(vector<vector<int>>& bottomLeft,
4                                vector<vector<int>>& topRight) {
5        int n = bottomLeft.size();
6        long long ans = 0;
7
8        for (int i = 0; i < n; i++) {
9            for (int j = i + 1; j < n; j++) {
10
11                int x1 = bottomLeft[i][0];
12                int y1 = bottomLeft[i][1];
13                int x2 = topRight[i][0];
14                int y2 = topRight[i][1];
15
16                int x3 = bottomLeft[j][0];
17                int y3 = bottomLeft[j][1];
18                int x4 = topRight[j][0];
19                int y4 = topRight[j][1];
20
21                int overlapWidth  = max(0, min(x2, x4) - max(x1, x3));
22                int overlapHeight = max(0, min(y2, y4) - max(y1, y3));
23
24                int side = min(overlapWidth, overlapHeight);
25                ans = max(ans, 1LL * side * side);
26            }
27        }
28
29        return ans;
30    }
31};