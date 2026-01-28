1class Solution {
2public:
3    int m, n;
4    vector<vector<int>> fn(vector<vector<int>>& v, vector<vector<int>>& a) {
5        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
6        dp[0][0] = v[0][0];
7        for (int i = 0; i < m; i++) {
8            for (int j = 0; j < n; j++) {
9                if (i > 0 && dp[i - 1][j] != INT_MAX)
10                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j]);
11                if (j > 0 && dp[i][j - 1] != INT_MAX)
12                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j]);
13                if (v[i][j] != INT_MAX)
14                    dp[i][j] = min(dp[i][j], v[i][j]);
15            }
16        }
17        return dp;
18    }
19    int minCost(vector<vector<int>>& a, int k) {
20        m = a.size(), n = a[0].size();
21        vector<vector<int>> dp1(m, vector<int>(n, INT_MAX));
22        dp1[0][0] = 0;
23        for (int i = 0; i < m; i++) {
24            for (int j = 0; j < n; j++) {
25                if (i > 0)
26                    dp1[i][j] = min(dp1[i][j], dp1[i - 1][j] + a[i][j]);
27                if (j > 0)
28                    dp1[i][j] = min(dp1[i][j], dp1[i][j - 1] + a[i][j]);
29            }
30        }
31        unordered_map<int, vector<pair<int, int>>> adj;
32        vector<int> dist;
33        for (int i = 0; i < m; i++) {
34            for (int j = 0; j < n; j++) {
35                int val = a[i][j];
36                if (!adj.count(val))
37                    dist.push_back(val);
38                adj[val].push_back({i, j});
39            }
40        }
41        sort(dist.begin(), dist.end(), greater<int>());
42
43        for (int t = 0; t < k; t++) {
44            vector<vector<int>> v(m, vector<int>(n, INT_MAX));
45            int mn1 = INT_MAX;
46            for (int val : dist) {
47                int mn2 = INT_MAX;
48                for (auto [i, j] : adj[val])
49                    mn2 = min(mn2, dp1[i][j]);
50                mn1 = min(mn1, mn2);
51                for (auto [i, j] : adj[val]) {
52                    v[i][j] = mn1;
53                }
54            }
55            vector<vector<int>> ans = fn(v, a);
56            for (int i = 0; i < m; i++) {
57                for (int j = 0; j < n; j++) {
58                    if (ans[i][j] < dp1[i][j])
59                        dp1[i][j] = ans[i][j];
60                }
61            }
62        }
63        return (int)dp1[m - 1][n - 1];
64    }
65};