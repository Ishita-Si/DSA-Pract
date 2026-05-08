1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        vector<int> hash(256,-1); // not seen
5        int l = 0 , r = 0;
6        int maxLen = 0;
7        
8        while(r < s.size()){
9            if(hash[s[r]] != -1){ //if seen
10                if(hash[s[r]] >= l) l = hash[s[r]] + 1; //update hash idx of elem
11            }
12            int len = r-l+1;
13            maxLen = max(len,maxLen);
14
15            hash[s[r]] = r;
16            r++;
17        }
18
19        return maxLen;
20    }
21};