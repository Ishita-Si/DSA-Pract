class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<long long> maxDp(n), minDp(n);

        maxDp[0] = grid[0][0];
        minDp[0] = grid[0][0];

        for (int j = 1; j < n; j++) {
            maxDp[j] = maxDp[j-1] * grid[0][j];
            minDp[j] = maxDp[j];
        }

        for (int i = 1; i < m; i++) {
            maxDp[0] = maxDp[0] * grid[i][0];
            minDp[0] = maxDp[0];

            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];

                long long a = maxDp[j] * val;    
                long long b = minDp[j] * val;    
                long long c = maxDp[j-1] * val;   
                long long d = minDp[j-1] * val;   

                long long newMax = max({a, b, c, d});
                long long newMin = min({a, b, c, d});

                maxDp[j] = newMax;
                minDp[j] = newMin;
            }
        }

        long long result = maxDp[n-1];

        if (result < 0) return -1;

        return result % MOD;
    }
};