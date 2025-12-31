1class Solution {
2public:
3    int row, col;
4    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
5
6    bool canCross(int day, vector<vector<int>>& cells) {
7        vector<vector<int>> grid(row, vector<int>(col, 0));
8
9        // mark flooded cells
10        for (int i = 0; i < day; i++) {
11            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
12        }
13
14        queue<pair<int,int>> q;
15        vector<vector<int>> vis(row, vector<int>(col, 0));
16
17        // start from top row
18        for (int j = 0; j < col; j++) {
19            if (grid[0][j] == 0) {
20                q.push({0, j});
21                vis[0][j] = 1;
22            }
23        }
24
25        while (!q.empty()) {
26            auto [r, c] = q.front();
27            q.pop();
28
29            if (r == row - 1) return true;
30
31            for (auto &d : dirs) {
32                int nr = r + d[0];
33                int nc = c + d[1];
34
35                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
36                    !vis[nr][nc] && grid[nr][nc] == 0) {
37                    vis[nr][nc] = 1;
38                    q.push({nr, nc});
39                }
40            }
41        }
42
43        return false;
44    }
45
46    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {
47        row = r;
48        col = c;
49
50        int low = 1, high = cells.size();
51        int ans = 0;
52
53        while (low <= high) {
54            int mid = low + (high - low) / 2;
55
56            if (canCross(mid, cells)) {
57                ans = mid;      // possible → try later days
58                low = mid + 1;
59            } else {
60                high = mid - 1; // impossible → go earlier
61            }
62        }
63
64        return ans;
65    }
66};
67