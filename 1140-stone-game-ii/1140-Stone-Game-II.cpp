class Solution {
public:
    int f(int i, int M, vector<int>& piles, vector<vector<int>>& dp, vector<int>& suffix) {
        if (i >= piles.size()) return 0;
        if (2 * M < piles.size() && dp[i][M] != -1) return dp[i][M];
        
        int ans = 0;
        for (int X = 1; X <= 2 * M && i + X <= piles.size(); X++) {
            int opponent = f(i + X, max(M, X), piles, dp, suffix);
            int current = suffix[i] - opponent;
            ans = max(ans, current);
        }
        
        if (2 * M < piles.size()) {
            dp[i][M] = ans;
        }
        return ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<int> suffix(n);
        
        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        
        return f(0, 1, piles, dp, suffix);
    }
};
