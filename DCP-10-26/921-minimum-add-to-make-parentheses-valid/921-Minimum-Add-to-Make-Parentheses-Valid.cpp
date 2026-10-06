class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int close = 0;

        for(char x : s){
            if(x == '(') cnt++;
            else if(x == ')'){
                cnt > 0 ? cnt-- : close++;;
            }
        }

        return cnt + close;
    }
};