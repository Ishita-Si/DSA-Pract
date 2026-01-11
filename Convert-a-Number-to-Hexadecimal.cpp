1class Solution {
2public:
3    string toHex(int num) {
4        if (num == 0) return "0";
5        string hexDigits = "0123456789abcdef";
6        string result = "";
7        unsigned int n = num;  
8        while (n > 0) {
9            result += hexDigits[n & 15]; 
10            n >>= 4;
11        }
12        reverse(result.begin(), result.end());
13        return result;
14    }
15};