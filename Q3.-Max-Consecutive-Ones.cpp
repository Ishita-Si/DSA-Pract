1class Solution {
2public:
3    int findMaxConsecutiveOnes(vector<int>& nums) {
4        int maxCount = 0;
5        int count = 0;
6        for(int i = 0; i <nums.size(); i++){
7           if (nums[i] == 1){
8            count++;
9            maxCount = max(count,maxCount);
10           }else count = 0;
11        }
12    return maxCount;
13    }
14};