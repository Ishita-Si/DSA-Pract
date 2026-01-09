1class Solution {
2public:
3    bool isPerfectSquare(int num) {
4        if (num < 1) return false;
5
6        long long x = num;
7        while (x * x > num) {
8            x = (x + num / x) / 2;
9        }
10        return x * x == num;
11    }
12};