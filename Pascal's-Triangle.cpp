1class Solution {
2public:
3    vector<vector<int>> generate(int numRows) {
4        vector<vector<int>> triangle;
5
6        for (int row = 0; row < numRows; row++) {
7            vector<int> curr(row + 1, 1);
8            for (int i = 1; i < row; i++) {
9                curr[i] = triangle[row - 1][i - 1] + triangle[row - 1][i];
10            }
11            triangle.push_back(curr);
12        }
13        return triangle;
14    }
15};