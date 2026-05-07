1class Solution {
2public:
3    int hammingWeight(int n) {
4        int count = 0;
5        while( n > 0){
6            count += (n & 1);
7            n >>= 1;
8        }
9
10        return count;
11    }
12};