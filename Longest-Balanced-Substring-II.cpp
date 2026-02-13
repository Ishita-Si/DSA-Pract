1class Solution {
2public:
3    int helper(string&s, int ch1, int ch2) {
4        int n = s.length();
5        unordered_map<int, int> diffMap;
6        int maxL = 0;
7        int count1 = 0;
8        int count2 = 0;
9
10        for(int i = 0; i < n; i++) {
11            if(s[i] != ch1 && s[i] != ch2) {
12                diffMap.clear();
13                count1 = 0;
14                count2 = 0;
15                continue;
16            }
17
18            if(s[i] == ch1)
19                count1++;
20            if(s[i] == ch2)
21                count2++;
22
23            if(count1 == count2) {
24                maxL = max(maxL, count1+count2);
25            }
26
27            int diff = count1 - count2;
28            if(diffMap.count(diff)) {
29                maxL = max(maxL, i - diffMap[diff]);
30            } else {
31                diffMap[diff] = i;
32            }
33        }
34        
35        return maxL;
36    }
37
38    int longestBalanced(string s) {
39        int n    = s.length();
40        int maxL = 0;
41
42        //Case-1
43        //"aaaa"
44        int count = 1; //s[0]
45        for(int i = 1; i < n; i++) {
46            if(s[i] == s[i-1]) {
47                count++;
48            } else {
49                maxL = max(maxL, count);
50                count = 1;
51            }
52        }
53        maxL = max(maxL, count);
54
55        //Case-2
56        maxL = max(maxL, helper(s, 'a', 'b'));
57        maxL = max(maxL, helper(s, 'a', 'c'));
58        maxL = max(maxL, helper(s, 'b', 'c'));
59
60
61        //Case-3
62        int countA = 0;
63        int countB = 0;
64        int countC = 0;
65        unordered_map<string, int> diffMap;
66
67        for(int i = 0; i < n; i++) {
68            if(s[i] == 'a')
69                countA++;
70            if(s[i] == 'b')
71                countB++;
72            if(s[i] == 'c')
73                countC++;
74
75            if(countA == countB && countA == countC) {
76                maxL = max(maxL, countA+countB+countC);
77            }
78
79            int diffAB = countA - countB;
80            int diffAC = countA - countC;
81
82            string key = to_string(diffAB) + "_" + to_string(diffAC); //log(n) digits
83
84            if(diffMap.count(key)) {
85                maxL = max(maxL, i - diffMap[key]);
86            } else {
87                diffMap[key] = i;
88            }
89        }
90
91        return maxL;
92
93    }
94};