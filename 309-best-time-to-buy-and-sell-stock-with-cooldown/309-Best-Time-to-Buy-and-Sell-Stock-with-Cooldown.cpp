class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<long> after(2,0), next(2,0), curr(2,0);

        for(int i = n-1; i >= 0; i--){
            curr[1] =  max(next[0] - prices[i], next[1]);
            curr[0] =  max(after[1] + prices[i], next[0]);

            after = next;
            next = curr;
        }

        return curr[1];
    }
};