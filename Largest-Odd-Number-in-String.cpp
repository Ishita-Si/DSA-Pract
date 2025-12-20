1class Solution {
2public:
3    string largestOddNumber(string num) {
4        for(int i = num.size() - 1; i >= 0; i--) {
5            int digit = num[i] - '0';
6            if(digit % 2 == 1) {
7                return num.substr(0, i + 1);
8            }
9        }
10        return "";
11    }
12};
13
14