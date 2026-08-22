class Solution {
public:
    int n;
    int f(int i, int j, vector<int>& stoneValue, vector<vector<int>>& dp, vector<int>& cumSum){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int score = 0;
        for(int k = i; k <= j-1; k++){
            int left = cumSum[k];
            if(i > 0) left -= cumSum[i - 1];
            int right = cumSum[j] - cumSum[k];
            if(left < right){
                score = max(score, left + f(i, k, stoneValue, dp, cumSum));
            }else if(right < left){
                score = max(score, right + f(k+1, j, stoneValue, dp, cumSum));
            }else{
                score = max({score, left + f(i, k, stoneValue, dp, cumSum), right + f(k+1, j, stoneValue, dp, cumSum)});
            }
        }
        return dp[i][j] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> cumSum(n);
        cumSum[0] = stoneValue[0];
        for(int i = 1; i < n; i++){
            cumSum[i] = cumSum[i-1] + stoneValue[i];
        }
        return f(0, n - 1, stoneValue, dp, cumSum);
    }
};
