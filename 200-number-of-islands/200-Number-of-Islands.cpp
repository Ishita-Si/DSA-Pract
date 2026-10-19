class Solution {
public:
    void bfs(vector<vector<char>>& grid,  vector<vector<bool>>& vis, int r, int c){
        queue<pair<int,int>> q;
        vis[r][c] = true;
        q.push({r,c});

        int m = grid.size();
        int n = grid[0].size();

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int newR = row + dr[k];
                int newC = col + dc[k];

                if(newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == '1' && !vis[newR][newC]){
                    vis[newR][newC] = true;
                    q.push({newR,newC});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        
        int island = 0;
        int n = grid[0].size();
        int m = grid.size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    island++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return island;
    }
};