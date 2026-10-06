class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater());
        sort(discounts.begin(), discounts.end(), greater());
        int i = 0;
        double sum = 0;

        while (i < prices.size() && i < discounts.size()) { 
            sum += (prices[i] * (100 - discounts[i])) / 100.0; 
            i++; 
        }

        if(i < prices.size()){
            while (i < prices.size()){
                sum += prices[i];
                i++;
            }
        }

        return sum;
    }
};