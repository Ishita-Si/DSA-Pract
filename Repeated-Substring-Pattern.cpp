1class Solution {
2public:
3    bool repeatedSubstringPattern(string s) {
4    string t = s + s;
5    return t.substr(1, t.size() - 2).find(s) != string::npos;
6}
7
8};