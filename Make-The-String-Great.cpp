1class Solution {
2public:
3    string makeGood(string s) {
4        stack<int> st;
5        for (int i = 0; i < s.size(); i++) {
6            if (!st.empty() && abs(st.top() - s[i]) == 32) {
7                st.pop();
8            } else {
9                st.push(s[i]);
10            }
11        }
12        string result;
13        while (!st.empty()) {
14            result.push_back(st.top());
15            st.pop();
16        }
17
18        reverse(result.begin(), result.end());
19        return result;
20    }
21};