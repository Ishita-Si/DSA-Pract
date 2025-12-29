1class Solution {
2public:
3    bool isSubsequence(string s, string t) {
4        int i = 0, j = 0;
5
6        while (i < s.size() && j < t.size()) {
7            if (s[i] == t[j]) {
8                i++;
9            }
10            j++;
11        }
12
13        return i == s.size();
14    }
15};
16