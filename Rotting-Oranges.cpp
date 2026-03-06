1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        int ans = 0;
7
8        vector<vector<bool>> vis(n, vector<bool>(m, false)); //!!
9        queue<pair<pair<int, int>, int>> q;
10        // pushing rotten oranges
11        for (int i = 0; i < n; i++) {
12            for (int j = 0 ; j < m; j++) {
13                if (grid[i][j] == 2) {
14                    q.push({{i, j}, 0});
15                    vis[i][j] = true;
16                }
17            }
18        }
19        // bfs
20        while (q.size() > 0) {
21            int i = q.front().first.first;
22            int j = q.front().first.second;
23            int time = q.front().second;
24            q.pop();
25
26            ans = max(ans, time);
27
28            if (i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == 1) {
29                q.push({{i - 1, j}, time + 1});
30                vis[i - 1][j] = true;
31            }
32            if (i+1 < n && !vis[i + 1][j] && grid[i + 1][j] == 1) {
33                q.push({{i + 1, j}, time + 1});
34                vis[i + 1][j] = true;
35            }
36            if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 1) {
37                q.push({{i, j - 1}, time + 1});
38                vis[i][j - 1] = true;
39            }
40            if (j+1 < m && !vis[i][j + 1] && grid[i][j + 1] == 1) {
41                q.push({{i, j + 1}, time + 1});
42                vis[i][j + 1] = true;
43            }
44        }
45        // check for left fresh oranges
46        for (int i = 0; i < n; i++) {
47            for (int j = 0; j < m; j++) {
48                if (grid[i][j] == 1 && !vis[i][j]) {
49                    return -1;
50                }
51            }
52        }
53        return ans;
54    }
55};