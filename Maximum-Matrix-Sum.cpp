1class Solution {
2public:
3    long long maxMatrixSum(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5        long long sum = 0;
6        int negative = 0;
7        int minAbs = INT_MAX;
8        for(int i = 0; i < n; i++){
9            for(int j = 0; j<n; j++){
10                sum += abs(matrix[i][j]);
11                if(matrix[i][j]<0){
12                    negative++;
13                }
14                minAbs = min(minAbs,abs(matrix[i][j]));
15            }
16        }
17        if(negative%2 == 0){
18            return sum;
19        }
20
21        return sum - 2*minAbs;
22    }
23};