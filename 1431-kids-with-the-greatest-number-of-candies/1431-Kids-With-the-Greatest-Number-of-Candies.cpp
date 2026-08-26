class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int i = *max_element(candies.begin(), candies.end());
        vector<bool> ans(candies.size(), false);
        int k = 0;

        for(int x : candies){
            if(x + extraCandies >= i){
                ans[k] = true;
            }
            k++;
        }

        return ans;
    }
};