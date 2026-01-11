1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4        stack<int> st;
5        heights.push_back(0); 
6        int maxArea = 0;
7
8        for (int i = 0; i < heights.size(); i++) {
9            while (!st.empty() && heights[st.top()] > heights[i]) {
10                int h = heights[st.top()];
11                st.pop();
12                int w = st.empty() ? i : i - st.top() - 1;
13                maxArea = max(maxArea, h * w);
14            }
15            st.push(i);
16        }
17        heights.pop_back();
18        return maxArea;
19    }
20
21    int maximalRectangle(vector<vector<char>>& matrix) {
22        if (matrix.empty()) return 0;
23
24        int rows = matrix.size(), cols = matrix[0].size();
25        vector<int> heights(cols, 0);
26        int ans = 0;
27
28        for (int i = 0; i < rows; i++) {
29            for (int j = 0; j < cols; j++) {
30                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
31            }
32            ans = max(ans, largestRectangleArea(heights));
33        }
34        return ans;
35    }
36};