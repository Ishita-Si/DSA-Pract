1class Solution {
2public:
3    int minLength(string s) {
4        stack<char> st;
5        string res = "";
6        for (int i = 0; i < s.size(); i++) {
7            st.push(s[i]);
8            if (st.size() >= 2) {
9                char second = st.top();
10                st.pop();
11                char first = st.top();
12                st.pop();
13                if (!((first == 'A' && second == 'B') ||
14                    (first == 'C' && second == 'D'))) {
15                    st.push(first);
16                    st.push(second);
17                }
18            }
19        }
20        while (!st.empty()) {
21            res += st.top();
22            st.pop();
23        }
24
25        return res.size();
26    }
27};