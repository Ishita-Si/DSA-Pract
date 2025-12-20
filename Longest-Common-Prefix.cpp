1class Solution {
2public:
3    string longestCommonPrefix(vector<string>& strs) {
4    if (strs.empty()) return "";
5
6    for (int i = 0; i < strs[0].size(); i++) {
7        char ch = strs[0][i];
8
9        for (int j = 1; j < strs.size(); j++) {
10            if (i >= strs[j].size() || strs[j][i] != ch) {
11                return strs[0].substr(0, i);
12            }
13        }
14    }
15    return strs[0];
16}
17
18};