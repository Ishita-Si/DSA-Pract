1class Solution {
2public:
3    int waysToMakeFair(vector<int>& nums) {
4        int totalEven = 0, totalOdd = 0;
5        for (int i = 0; i < nums.size(); i++) {
6            if (i % 2 == 0) totalEven += nums[i];
7            else totalOdd += nums[i];
8        }
9        int leftEven = 0, leftOdd = 0;
10        int ways = 0;
11
12        for (int i = 0; i < nums.size(); i++) {
13            if (i % 2 == 0) totalEven -= nums[i];
14            else totalOdd -= nums[i];
15
16            int newEven = leftEven + totalOdd;
17            int newOdd  = leftOdd  + totalEven;
18            
19            if (newEven == newOdd) ways++;
20
21            if (i % 2 == 0) leftEven += nums[i];
22            else leftOdd += nums[i];
23            }
24        
25        return ways;
26
27    }
28};