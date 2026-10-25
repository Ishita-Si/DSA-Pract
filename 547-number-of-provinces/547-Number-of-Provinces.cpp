class Solution {
public:
    void dfs(int start, vector<vector<int>>& adj,vector<bool>& vis){
        vis[start] = true;

        for(int i = 0 ; i < adj[start].size(); i++){
            int node = adj[start][i];
            if(!vis[node]){
                dfs(node, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        vector<bool> vis(n);
        int prov = 0;

        for(int i = 0; i < n;i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj,vis);
                prov++;
            }
        }

        return prov;
    }
};