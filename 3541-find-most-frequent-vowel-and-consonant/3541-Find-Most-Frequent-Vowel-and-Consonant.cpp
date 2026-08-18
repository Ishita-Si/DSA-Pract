class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        if(n == 0) return 0;

        unordered_map<char,int> freq;
        int maxVow = 0;
        int maxCons = 0;

        for(char x : s){
            freq[x]++;
        }

        for(char x : s){
            if(x == 'a'||x == 'e'||x == 'i'||x == 'o'||x == 'u'){
                maxVow = max(maxVow,freq[x]);
            }else{
                maxCons = max(maxCons,freq[x]);
            }
        }

        return maxVow + maxCons;
    }
};