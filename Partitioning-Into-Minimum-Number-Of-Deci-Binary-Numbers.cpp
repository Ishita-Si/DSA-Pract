1class Solution {
2public:
3    int minPartitions(string n) {
4        int maxDigit = 0;
5        
6        for (char c : n) {
7            maxDigit = max(maxDigit, c - '0');
8        }
9        
10        return maxDigit;
11    }
12};