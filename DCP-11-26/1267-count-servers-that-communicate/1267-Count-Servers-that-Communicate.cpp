class Solution {
public:
    int bfs(vector<bool>& vis, vector<vector<int>>& adj, int i, int m){
        int cnt = 0;
        queue<int> q;

        q.push(i);
        vis[i] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if (node < m)
            cnt += adj[node].size();

            for(int x : adj[node]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = true;
                }
            }
        }

        return cnt;
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<bool> vis(m+n,false);
        vector<vector<int>> adj(m+n);
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    adj[i].push_back(m + j);
                    adj[m + j].push_back(i);
                }
            }
        }

        for(int i = 0; i < m+n; i++){
            if(!vis[i]){
                int cnt = bfs(vis, adj, i, m);
                if(cnt != 1) count += cnt;
            } 
        }

        return count;
    }
};