1class Solution {
2public:
3    int largestMagicSquare(vector<vector<int>>& grid) {
4        int m = grid.size(), n = grid[0].size();
5        vector<vector<int>> row(m, vector<int>(n+1, 0)),
6                            col(m+1, vector<int>(n, 0)),
7                            diag(m+1, vector<int>(n+1, 0)),
8                            anti(m+1, vector<int>(n+1, 0));
9
10        for(int i = 0; i < m; i++) {
11            for(int j = 0; j < n; j++) {
12                row[i][j+1] = row[i][j] + grid[i][j];
13                col[i+1][j] = col[i][j] + grid[i][j];
14                diag[i+1][j+1] = diag[i][j] + grid[i][j];
15                anti[i+1][j] = anti[i][j+1] + grid[i][j];
16            }
17        }
18
19        for(int k = min(m, n); k >= 2; k--) {
20            for(int i = 0; i + k <= m; i++) {
21                for(int j = 0; j + k <= n; j++) {
22                    int target = row[i][j+k] - row[i][j];
23                    bool ok = true;
24
25                    for(int r = i; r < i + k && ok; r++)
26                        if(row[r][j+k] - row[r][j] != target) ok = false;
27
28                    for(int c = j; c < j + k && ok; c++)
29                        if(col[i+k][c] - col[i][c] != target) ok = false;
30
31                    int d1 = diag[i+k][j+k] - diag[i][j];
32                    int d2 = anti[i+k][j] - anti[i][j+k];
33                    if(d1 != target || d2 != target) ok = false;
34
35                    if(ok) return k;
36                }
37            }
38        }
39        return 1;
40    }
41};