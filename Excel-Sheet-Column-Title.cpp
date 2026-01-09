1class Solution {
2public:
3    string convertToTitle(int n) {
4        string result = "";
5
6        while (n > 0) {
7            n--;                            
8            char c = 'A' + (n % 26);
9            result.push_back(c);
10            n /= 26;
11        }
12        reverse(result.begin(), result.end());
13        return result;
14    }
15};