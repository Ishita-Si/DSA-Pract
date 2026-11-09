class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = 0;
        int previ, prevj = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        while(i < m && i >= 0 && j < n && j >= 0 && !vis[i][j]){
            vis[i][j] = true;
            previ = i;
            prevj = j;

            if(grid[i][j] == 'R') j++;
            else if(grid[i][j] == 'L') j--;
            else if(grid[i][j] == 'U') i--;
            else i++;
        }

        return {previ,prevj};
    }
};