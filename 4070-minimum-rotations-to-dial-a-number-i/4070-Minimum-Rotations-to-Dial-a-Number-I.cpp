class Solution {
public:
    int minRotations(string s) {
        int sum = 0;
        int curPos = 0;

        for(char x : s){
            int t = x - '0';
            sum += min(10 - abs(t - curPos), abs(t - curPos));
            curPos = t;
        }

        return sum;
    }
};