class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> freq;
        int n = s.size();
        int l = 0;
        int r = 0;
        int len = 0;
        int maxLen = 0;

        while(r < n){
            freq[s[r]]++;
            len++;

            while(freq[s[r]] > 2){
                freq[s[l]]--;
                len--;
                l++;

            }
            maxLen = max(len, maxLen);
            r++;
        }

        return maxLen;
    }
};