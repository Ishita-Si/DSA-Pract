class Solution {
public:
    long long dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c){
        int m = grid.size();
        int n = grid[0].size();

        vis[r][c] = true;
        long long cost = grid[r][c];

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nc < n && nc >= 0 && nr >= 0 && nr < m && grid[nr][nc] != 0 && !vis[nr][nc]){
                cost += dfs(grid, vis, nr, nc);
            }
        }

        return cost;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0 && !vis[i][j]){
                    long long landCost = dfs(grid,vis,i,j);
                    if(k != 0 && landCost % k == 0) island++;
                }
            }
        }
        return island;
    }
};