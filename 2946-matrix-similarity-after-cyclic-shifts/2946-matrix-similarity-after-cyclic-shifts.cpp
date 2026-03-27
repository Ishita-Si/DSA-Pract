class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> grid = mat;

        k = k % m;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i % 2 == 0) {
                    grid[i][(j + k) % m] = mat[i][j];
                } else {
                    grid[i][(j - k + m) % m] = mat[i][j];
                }
            }
        }

        return grid == mat;
    }
};