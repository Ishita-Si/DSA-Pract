1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int len = 0;
5        int maxLen = 0;
6        for(int i = 0; i < s.size(); i++){
7            int hash[256] = {0};
8            for(int j = i ; j< s.size(); j++){
9                if (hash[s[j]] == 1) break;
10                len = j -i +1;
11                maxLen = max(len , maxLen);
12                hash[s[j]] = 1;
13            }
14        }
15        return maxLen;
16    }
17};