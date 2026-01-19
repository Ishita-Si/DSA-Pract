1class Solution {
2public:
3    int maxSideLength(vector<vector<int>>& mat, int threshold) {
4        int m = mat.size();
5        int n = mat[0].size();
6
7        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
8
9        for (int i = 1; i <= m; i++) {
10            for (int j = 1; j <= n; j++) {
11                pre[i][j] = mat[i - 1][j - 1]
12                          + pre[i - 1][j]
13                          + pre[i][j - 1]
14                          - pre[i - 1][j - 1];
15            }
16        }
17
18        int low = 0, high = min(m, n), ans = 0;
19
20        while (low <= high) {
21            int mid = (low + high) / 2;
22            bool possible = false;
23
24            for (int i = mid; i <= m; i++) {
25                for (int j = mid; j <= n; j++) {
26                    int sum = pre[i][j]
27                            - pre[i - mid][j]
28                            - pre[i][j - mid]
29                            + pre[i - mid][j - mid];
30
31                    if (sum <= threshold) {
32                        possible = true;
33                        break;
34                    }
35                }
36                if (possible) break;
37            }
38
39            if (possible) {
40                ans = mid;
41                low = mid + 1;
42            } else {
43                high = mid - 1;
44            }
45        }
46
47        return ans;
48    }
49};