1class Solution {
2public:
3    string clearDigits(string s) {
4        stack<char> st;
5        for (int i = 0; i < s.size(); i++) {
6            if ((s[i] >= '0' && s[i] <= '9') && !st.empty()) {
7                st.pop();
8            } else {
9                st.push(s[i]);
10            }
11        }
12        string res = "";
13        while(!st.empty()){
14            res += st.top();
15            st.pop();
16        }
17        reverse(res.begin(),res.end());
18        return res;
19    }
20};