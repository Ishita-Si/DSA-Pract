1class Solution {
2public:
3    vector<int> constructRectangle(int area) {
4        for (int w = sqrt(area); w >= 1; w--) {
5            if (area % w == 0) {
6                int l = area / w;
7                return {l, w};
8            }
9        }
10        return {};
11    }
12};