1class Solution {
2public:
3    bool hasAlternatingBits(int n) {
4         int prev = n & 1; 
5        n = n >> 1;
6
7        while(n > 0) {
8            int curr = n & 1;
9
10            if(curr == prev)
11                return false;
12
13            prev = curr;
14            n = n >> 1;
15        }
16
17        return true;
18    }
19};