1class Solution {
2public:
3    int longestBalanced(string s) {
4        int n = s.length();
5        int maxLen = 0;
6
7        for (int i = 0; i < n; i++) {
8
9            vector<int> freq(26, 0);
10            int distinct = 0;
11            int maxFreq = 0;
12
13            for (int j = i; j < n; j++) {
14
15                int index = s[j] - 'a';
16
17                if (freq[index] == 0)
18                    distinct++;
19
20                freq[index]++;
21                maxFreq = max(maxFreq, freq[index]);
22
23                int length = j - i + 1;
24
25                if (maxFreq * distinct == length)
26                    maxLen = max(maxLen, length);
27            }
28        }
29
30        return maxLen;
31    }
32};