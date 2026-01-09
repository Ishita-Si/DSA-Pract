1class Solution {
2public:
3    int titleToNumber(string col) {
4        int sum = 0;
5        for (char c : col) {
6            int value = c - 'A' + 1;
7            sum = sum * 26 + value;
8        }
9        return sum;
10    }
11};