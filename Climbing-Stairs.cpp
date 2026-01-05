1class Solution {
2public:
3    int climbStairs(int n) {
4        if (n <= 2) return n;
5
6        int prev2 = 1; 
7        int prev1 = 2; 
8
9        for (int i = 3; i <= n; i++) {
10            int curr = prev1 + prev2;
11            prev2 = prev1;
12            prev1 = curr;
13        }
14        return prev1;
15    }
16};