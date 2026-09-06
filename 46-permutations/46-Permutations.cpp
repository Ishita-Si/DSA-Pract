class Solution {
public:
    void permutations(int idx,vector<int>& nums, vector<vector<int>>& perm){
        int n = nums.size();
        if(idx == n){
          perm.push_back({nums});
          return;  
        } 

        for(int i = idx; i < n; i++){
            swap(nums[idx],nums[i]);
            permutations(idx+1, nums, perm);

            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perm;
        
        permutations(0, nums, perm);
        return perm;
    }
};