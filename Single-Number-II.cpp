1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin(),nums.end());
6        for(int i = 1; i < n; i = i+3){
7            if(nums[i-1] != nums[i]) return nums[i-1];
8            if( nums[i+1] != nums[i] ) return nums[i+1];
9        }
10
11        return nums[n-1];
12    }
13};