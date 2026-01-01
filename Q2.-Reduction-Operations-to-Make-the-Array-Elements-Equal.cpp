1class Solution {
2public:
3    int reductionOperations(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        long long oper = 0;
6        int steps = 0;
7
8        for (int i = 1; i < nums.size(); i++) {
9            if (nums[i] != nums[i - 1]) {
10                steps++; 
11            }
12            oper += steps;
13        }
14        return oper;
15    }
16};