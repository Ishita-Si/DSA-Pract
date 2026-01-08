1class Solution {
2public:
3    int addDigits(int num) {
4        if (num == 0)
5            return 0;
6        else {
7            return num%9 == 0 ? 9 :num % 9;
8        }
9    }
10};