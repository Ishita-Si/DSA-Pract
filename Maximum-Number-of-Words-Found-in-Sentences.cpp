1class Solution {
2public:
3    int mostWordsFound(vector<string>& sentences) {
4        int maxCount = 0;
5
6        for (string s : sentences) {
7            int count = 0;
8            for (char c : s) {
9                if (c == ' ') count++;
10            }
11            maxCount = max(maxCount, count + 1);
12        }
13        return maxCount;
14    }
15};