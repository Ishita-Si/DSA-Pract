1class Solution {
2public:
3    vector<string> ans;
4    void backtrack(string curr, int open, int close, int n) {
5        if (curr.size() == 2 * n) {
6            ans.push_back(curr);
7            return;
8        }
9
10        if (open < n) {
11            backtrack(curr + "(", open + 1, close, n);
12        }
13
14        if (close < open) {
15            backtrack(curr + ")", open, close + 1, n);
16        }
17    }
18
19    vector<string> generateParenthesis(int n) {
20        backtrack("", 0, 0, n);
21        return ans;
22    }
23};