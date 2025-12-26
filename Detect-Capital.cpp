1class Solution {
2public:
3    bool detectCapitalUse(string s) {
4        int n = s.size();
5        if (n == 1) return true;
6
7        if (s[0] >= 'A' && s[0] <= 'Z' &&
8            s[1] >= 'A' && s[1] <= 'Z') {
9
10            for (int i = 2; i < n; i++) {
11                if (!(s[i] >= 'A' && s[i] <= 'Z'))
12                    return false;
13            }
14        }
15        else {
16            for (int i = 1; i < n; i++) {
17                if (!(s[i] >= 'a' && s[i] <= 'z'))
18                    return false;
19            }
20        }
21
22        return true;
23    }
24};
25