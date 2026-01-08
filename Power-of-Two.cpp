1class Solution {
2public:
3    bool isPowerOfTwo(int n) {
4        if( n <= 0) return false;
5        
6        while (n > 1) {
7        if (n % 2 != 0) return false;
8        n /= 2;
9    }
10    return true;
11    }
12};