1class Solution {
2public:
3    int repeatedNTimes(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        for(int i = 0; i < 2*nums.size(); i++){
6            if(nums[i]==nums[i+1]){
7                return nums[i];
8            }
9        }
10        return 0;
11    }
12};