1class Solution {
2public:
3    int minFlips(string s) {
4        int n = s.size();
5        s += s;
6
7        string s1, s2;
8
9        for(int i = 0; i < 2*n; i++) {
10            s1 += (i % 2 ? '0' : '1');
11            s2 += (i % 2 ? '1' : '0');
12        }
13
14        int i = 0, j = 0;
15        int result1 = 0, result2 = 0;
16        int result = INT_MAX;
17
18        while(j < 2*n) {
19
20            // expand window
21            if(s[j] != s1[j]) result1++;
22            if(s[j] != s2[j]) result2++;
23
24            // shrink if window exceeds n
25            if(j - i + 1 > n) {
26                if(s[i] != s1[i]) result1--;
27                if(s[i] != s2[i]) result2--;
28                i++;
29            }
30
31            // window size exactly n
32            if(j - i + 1 == n)
33                result = min({result, result1, result2});
34
35            j++;
36        }
37
38        return result;
39    }
40};