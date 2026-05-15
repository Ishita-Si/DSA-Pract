1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        map<char,int> mpp;
5        int n = s.size();
6        int l = 0, r = 0;
7        int maxFreq = 0;
8        int maxLen = 0;
9
10        while(r < n){
11            mpp[s[r]]++;
12            maxFreq = max(maxFreq,mpp[s[r]]);
13            if((r-l+1) - maxFreq > k){
14                mpp[s[l]]--;
15                l++;
16            }
17
18            maxLen = max(maxLen , r-l+1);
19            r++;
20        }
21
22        return maxLen;
23    }
24};