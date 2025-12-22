1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int n = strs.size();
5        int m = strs[0].size();
6
7        vector<int> dp(m, 1);  
8
9        for (int j = 0; j < m; j++) {
10            for (int i = 0; i < j; i++) {
11                bool valid = true;
12                for (int r = 0; r < n; r++) {
13                    if (strs[r][i] > strs[r][j]) {
14                        valid = false;
15                        break;
16                    }
17                }
18                if (valid) {
19                    dp[j] = max(dp[j], dp[i] + 1);
20                }
21            }
22        }
23
24        int longest = 0;
25        for (int len : dp) {
26            longest = max(longest, len);
27        }
28
29        return m - longest;
30    }
31};
32