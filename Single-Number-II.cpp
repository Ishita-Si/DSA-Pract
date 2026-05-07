1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int ones = 0; 
5        int twos = 0;
6
7        for(int i = 0; i < nums.size(); i++){
8            ones = (ones^nums[i]) & ~ twos;
9            twos = (twos^nums[i]) & ~ ones;
10        }
11
12        return ones;
13    }
14};