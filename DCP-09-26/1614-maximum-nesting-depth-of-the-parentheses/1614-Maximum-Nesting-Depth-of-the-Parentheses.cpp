class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int maxi = 0;
        int paren = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                paren++;
                maxi = max(maxi, paren);
            }else if(s[i] == ')'){
                paren--;
            }
        }

        return maxi;
    }
};