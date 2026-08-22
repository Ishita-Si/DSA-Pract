class Solution {
public:
    int n;
    int f(int player, int i, int M, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if(i >= n) return 0;
        int res = (player == 1) ? -1 : INT_MAX;
        int stone = 0;
        if (M > n) M = n;

        if(dp[i][M][player] != -1) return dp[i][M][player];

        for(int x = 1; x <= min(2*M,n-i);x++){
            stone += piles[i + x -1];
            if(player == 1){
                res = max(res, stone + f(0,i+x,max(M,x), piles, dp));
            }else{
                res = min(res, f(1,i+x,max(M,x), piles, dp));
            }
        }
        return dp[i][M][player] = res;
        
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2*n, vector<int>(2,-1)));
        
        return f(1, 0, 1, piles, dp);
    }
};
