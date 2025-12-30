1class Solution {
2public:
3    bool isMagic(vector<vector<int>>& g, int r, int c) {
4        vector<bool> seen(10, false);
5
6        for (int i = r; i < r + 3; i++) {
7            for (int j = c; j < c + 3; j++) {
8                int val = g[i][j];
9                if (val < 1 || val > 9 || seen[val]) return false;
10                seen[val] = true;
11            }
12        }
13
14        for (int i = 0; i < 3; i++) {
15            if (g[r + i][c] + g[r + i][c + 1] + g[r + i][c + 2] != 15)
16                return false;
17        }
18
19        for (int j = 0; j < 3; j++) {
20            if (g[r][c + j] + g[r + 1][c + j] + g[r + 2][c + j] != 15)
21                return false;
22        }
23
24        if (g[r][c] + g[r + 1][c + 1] + g[r + 2][c + 2] != 15)
25            return false;
26        if (g[r][c + 2] + g[r + 1][c + 1] + g[r + 2][c] != 15)
27            return false;
28
29        return true;
30    }
31
32    int numMagicSquaresInside(vector<vector<int>>& grid) {
33        int m = grid.size(), n = grid[0].size();
34        int count = 0;
35
36        for (int i = 0; i <= m - 3; i++) {
37            for (int j = 0; j <= n - 3; j++) {
38                if (isMagic(grid, i, j))
39                    count++;
40            }
41        }
42        return count;
43    }
44};
45