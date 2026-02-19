1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4        
5        int prev = 0;
6        int curr = 1;
7        int result = 0;
8        
9        for(int i = 1; i < s.size(); i++) {
10            
11            if(s[i] == s[i-1]) {
12                curr++;
13            }
14            else {
15                result += min(prev, curr);
16                prev = curr;
17                curr = 1;
18            }
19        }
20        
21        result += min(prev, curr);
22        
23        return result;
24    }
25};
26