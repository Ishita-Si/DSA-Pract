1class Solution {
2public:
3    int reverseBits(int n) {
4        int result = 0;
5
6        for (int i = 0; i < 32; i++) {
7            int lastBit = n & 1;       
8            result = result << 1;     
9            result = result | lastBit; 
10            n = n >> 1;               
11        }
12
13        return result;
14    }
15};