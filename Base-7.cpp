1class Solution {
2public:
3    string convertToBase7(int n) {
4        if (n == 0)
5            return "0";
6        bool negative = n < 0;
7        n = abs(n);
8        string res = "";
9        while (n > 0) {
10            res = char('0' + (n % 7)) + res;
11            n /= 7;
12        }
13        if (negative)
14            res = "-" + res;
15        return res;
16    }
17};