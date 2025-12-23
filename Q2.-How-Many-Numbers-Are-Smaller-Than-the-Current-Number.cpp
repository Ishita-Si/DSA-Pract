1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        vector<int> arr(nums.size());
5
6        for(int i = 0; i < nums.size(); i++){
7            int count = 0;
8            for(int j = 0; j < nums.size(); j++){
9                if(nums[i]>nums[j]){
10                    count++;
11                }
12            }
13            arr[i] = count;
14        }
15    return arr;
16    }
17};