1class Solution {
2public:
3    void dfs(int city, vector<vector<int>>& isConnected,
4             vector<bool>& visited) {
5        visited[city] = true;
6
7        for (int j = 0; j < isConnected.size(); j++) {
8            if (isConnected[city][j] == 1 && !visited[j]) {
9                dfs(j, isConnected, visited);
10            }
11        }
12    }
13
14    int findCircleNum(vector<vector<int>>& isConnected) {
15        int n = isConnected.size();
16        vector<bool> visited(n, false);
17        int provinces = 0;
18
19        for (int i = 0; i < n; i++) {
20            if (!visited[i]) {
21                dfs(i, isConnected, visited);
22                provinces++;
23            }
24        }
25
26        return provinces;
27    }
28};