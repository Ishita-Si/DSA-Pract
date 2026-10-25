class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> vis(n, vector<int>(n, false));

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

        queue<tuple<int, int, int>> q;

        q.push({0, 0, 1});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [r, c, d] = q.front();
            q.pop();

            // Step 1: Check if we reached the destination
            if (r == n - 1 && c == n - 1)
                return d;

            // Step 2: Explore all 8 directions
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Step 3: Check boundaries
                if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;

                // Step 4: Check if the cell is open and unvisited
                if (grid[nr][nc] == 0 && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push({nr, nc, d + 1});
                }
            }
        }

        return -1;
    }
};