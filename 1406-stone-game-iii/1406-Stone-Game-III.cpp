class Solution {
public:
    int n;
    int f(int player, int i, int M, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if(i >= n) return 0;
        
        int res = (player == 1) ? INT_MIN : INT_MAX;
        int stone = 0;

        if(dp[i][M][player] != -1) return dp[i][M][player];

        for(int x = 1; x <= min(3, n-i); x++){
            stone += piles[i + x - 1];
            if(player == 1){
                res = max(res, stone + f(0, i + x, M, piles, dp));
            }else{
                res = min(res, f(1, i + x, M, piles, dp));
            }
        }
        return dp[i][M][player] = res;
    }

    string stoneGameIII(vector<int>& piles) {
        n = piles.size();
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, -1)));

        int total_stones = 0;
        for(int s : piles) total_stones += s;

        int alice_score = f(1, 0, 1, piles, dp);
        int bob_score = total_stones - alice_score;

        if(alice_score > bob_score) return "Alice";
        else if(alice_score < bob_score) return "Bob";
        else return "Tie";
    }
};
