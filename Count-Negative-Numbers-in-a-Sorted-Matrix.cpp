1class Solution {
2public:
3    int countNegatives(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid.empty() ? 0 : grid[0].size();
6        int count = 0;
7
8        for(int i = 0; i < m; i++){
9            for(int j = 0; j < n; j++){
10                if(grid[i][j] < 0){
11                    count++;
12                }
13            }
14        }
15    return count;
16    }
17};