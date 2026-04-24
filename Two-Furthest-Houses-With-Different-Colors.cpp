1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int n = colors.size();
5        int ans = 0;
6        for (int j = n - 1; j >= 0; j--) {
7            if (colors[j] != colors[0]) {
8                ans = j;
9                break;
10            }
11        }
12        for (int i = 0; i < n; i++) {
13            if (colors[i] != colors[n - 1]) {
14                ans = max(ans, n - 1 - i);
15                break;
16            }
17        }
18
19        return ans;
20    }
21};