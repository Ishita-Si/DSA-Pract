1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4        int count = 0;
5        string ans = "";
6        for(int i = 0; i < s.length(); i++){
7            if(s[i] ==')')count--;
8            if(count != 0)ans.push_back(s[i]);
9            if(s[i]=='(')count++;
10        }
11    return ans;
12    }
13};