class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<long> after(2,0), curr(2,0);

        for(int i = n-1; i >= 0; i--){
            curr[1] =  max(after[0] - prices[i] , after[1]);
            curr[0] =  max(after[1] + prices[i] - fee , after[0]);

            after = curr;
        }

        return curr[1];
    }
};