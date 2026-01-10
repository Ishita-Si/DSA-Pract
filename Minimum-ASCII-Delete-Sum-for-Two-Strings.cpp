1class Solution {
2public:
3    int minimumDeleteSum(string s1, string s2) {
4        int n = s1.size(), m = s2.size();
5        
6        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
7        
8        for (int i = 1; i <= n; i++) {
9            for (int j = 1; j <= m; j++) {
10                if (s1[i - 1] == s2[j - 1]) {
11                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
12                } else {
13                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
14                }
15            }
16        }
17        
18        int sum1 = 0, sum2 = 0;
19        for (char c : s1) sum1 += c;
20        for (char c : s2) sum2 += c;
21        
22        return sum1 + sum2 - 2 * dp[n][m];
23    }
24};