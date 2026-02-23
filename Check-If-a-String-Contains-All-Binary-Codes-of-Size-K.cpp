1class Solution {
2public:
3    bool hasAllCodes(string s, int k) {
4        int n = s.size();
5        int total = 1 << k;
6        
7        if (n - k + 1 < total) return false;
8        
9        vector<bool> seen(total, false);
10        int count = 0;
11        int mask = total - 1;
12        int num = 0;
13        
14        for (int i = 0; i < n; i++) {
15            num = ((num << 1) & mask) | (s[i] - '0');
16            
17            if (i >= k - 1) {
18                if (!seen[num]) {
19                    seen[num] = true;
20                    count++;
21                    if (count == total) return true;
22                }
23            }
24        }
25        
26        return false;
27    }
28};