class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        int subs = 1 << n; // 2^n loop 

        for(int num = 0; num < subs; num++){
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (num & (1 << i)) { // chooses the positions of elm in nums.
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }

        return ans;
    }
};