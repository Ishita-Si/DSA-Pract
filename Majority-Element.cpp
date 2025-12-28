1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        int candidate = 0;
5        int count = 0;
6
7        for (int x : nums) {
8            if (count == 0) {
9                candidate = x;  
10            }
11            if (x == candidate) {
12                count++;    
13            } else {
14                count--;      
15            }
16        }
17        return candidate;      
18    }
19};
20