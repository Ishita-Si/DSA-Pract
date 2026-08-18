class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int degree = 0;

        for(int i = 0; i < n; i++){
            int prod = (26 - (s[i] - 'a')) * (i+1);
            degree += prod;
        }

        return degree;
    }
};