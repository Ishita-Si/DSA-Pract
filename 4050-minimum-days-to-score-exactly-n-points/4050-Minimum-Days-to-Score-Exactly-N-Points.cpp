class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        vector<pair<int, int>> streaks;
        for(int k = 1; ; ++k){
            int points = k * (k + 1)/2;
            if(points > n) break;
            streaks.push_back({points, k});
        }

        for(int i = 1; i <= n ;++i){
            for(const auto& streak : streaks){
                int p = streak.first;
                int days = streak.second;

                if(i - p >= 0){
                    if(i - p == 0){
                        dp[i] = min(dp[i], days);
                    }

                    else if(dp[i - p] != INT_MAX){
                        dp[i] = min(dp[i], dp[i - p] + 1 + days);
                    }
                }
            }
        }

        return dp[n];
    }
};