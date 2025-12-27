1class Solution {
2public:
3    bool repeatedSubstringPattern(string s) {
4    int n = s.size();
5
6    for (int len = 1; len <= n / 2; len++) {
7        if (n % len != 0) continue;
8
9        string pattern = s.substr(0, len);
10        string built = "";
11
12        for (int i = 0; i < n / len; i++) {
13            built += pattern;
14        }
15
16        if (built == s) return true;
17    }
18
19    return false;
20}
21};