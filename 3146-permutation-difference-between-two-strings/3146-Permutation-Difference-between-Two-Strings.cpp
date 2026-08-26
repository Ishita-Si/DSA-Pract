class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int> mpp;
        int sum = 0;

        for (int i = 0; i < t.length(); i++) {
            mpp[t[i]] = i;
        }

        for(int i = 0; i < s.size(); i++){
            sum += abs(mpp[s[i]] - i);
        }
        return sum;
    }
};