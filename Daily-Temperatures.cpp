1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temp) {
4        int n = temp.size();
5        vector<int> ans(n, 0);
6        stack<int> st; 
7
8        for (int i = 0; i < n; i++) {
9            while (!st.empty() && temp[i] > temp[st.top()]) {
10                int idx = st.top();
11                st.pop();
12                ans[idx] = i - idx;
13            }
14            st.push(i);
15        }
16        return ans;
17    }
18};
19