1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int n = strs.size();
5        int m = strs[0].size();
6        
7        vector<bool> sorted(n - 1, false);
8        int deletions = 0;
9
10        for (int col = 0; col < m; col++) {
11            bool bad = false;
12
13            for (int i = 0; i < n - 1; i++) {
14                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
15                    bad = true;
16                    break;
17                }
18            }
19
20            if (bad) {
21                deletions++;
22                continue;
23            }
24
25            for (int i = 0; i < n - 1; i++) {
26                if (!sorted[i] && strs[i][col] < strs[i + 1][col]) {
27                    sorted[i] = true;
28                }
29            }
30        }
31
32        return deletions;
33    }
34};
35