1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        if (needle.empty()) return 0;
5        if (haystack.size() < needle.size()) return -1;
6
7        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
8            int j = 0;
9
10            while (j < needle.size() && haystack[i + j] == needle[j]) {
11                j++;
12            }
13
14            if (j == needle.size()) {
15                return i;   
16            }
17        }
18
19        return -1;        
20    }
21};