1class Solution {
2public:
3    int maxConsecutive(vector<int>& bars) {
4        sort(bars.begin(), bars.end());
5        int maxLen = 1, curr = 1;
6
7        for (int i = 1; i < bars.size(); i++) {
8            if (bars[i] == bars[i - 1] + 1) {
9                curr++;
10            } else {
11                curr = 1;
12            }
13            maxLen = max(maxLen, curr);
14        }
15        return maxLen + 1;
16    }
17
18    int maximizeSquareHoleArea(int n, int m,
19                               vector<int>& hBars,
20                               vector<int>& vBars) {
21        int h = maxConsecutive(hBars);
22        int v = maxConsecutive(vBars);
23        int side = min(h, v);
24        return side * side;
25    }
26};