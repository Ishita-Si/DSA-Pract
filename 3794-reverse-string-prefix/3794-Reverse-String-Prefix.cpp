class Solution {
public:
    string reversePrefix(string s, int k) {
        string t = "";
        int n = s.size();

        for(int i = k-1; i >= 0; i--){
            t.push_back(s[i]);
        }

        for(int i = k; i < n; i++){
            t.push_back(s[i]);
        }

        return t;
    }
};