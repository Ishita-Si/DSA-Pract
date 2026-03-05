1class Solution {
2public:
3    int minOperations(string s) {
4        int start0 = 0; // pattern 010101...
5        int start1 = 0; // pattern 101010...
6
7        for(int i = 0; i < s.size(); i++) {
8            char expected0 = (i % 2 == 0) ? '0' : '1';
9            char expected1 = (i % 2 == 0) ? '1' : '0';
10
11            if(s[i] != expected0) start0++;
12            if(s[i] != expected1) start1++;
13        }
14
15        return min(start0, start1);
16    }
17};