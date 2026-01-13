1class Solution {
2public:
3    double separateSquares(vector<vector<int>>& squares) {
4        double low = 1e9, high = -1e9;
5        
6        for (auto &s : squares) {
7            low = min(low, (double)s[1]);
8            high = max(high, (double)(s[1] + s[2]));
9        }
10
11        for (int iter = 0; iter < 60; iter++) {
12            double mid = (low + high) / 2.0;
13            double below = 0, above = 0;
14
15            for (auto &s : squares) {
16                double y = s[1];
17                double side = s[2];
18
19                if (mid <= y) {
20                    above += side * side;
21                } else if (mid >= y + side) {
22                    below += side * side;
23                } else {
24                    double h = mid - y;
25                    below += h * side;
26                    above += (side - h) * side;
27                }
28            }
29
30            if (below < above)
31                low = mid;
32            else
33                high = mid;
34        }
35        return (low + high) / 2.0;
36    }
37};