1class Solution {
2public:
3    int minSwaps(vector<vector<int>>& grid) {
4        int n = grid.size(); // rows == columns
5
6        vector<int> endZeros(n, 0);
7        //endZeros[i] = count of consecutive 0s from the end of ith row
8
9        for(int i = 0; i < n; i++) {
10            int j = n-1; //start from end
11
12            int count = 0;
13            while(j >= 0 && grid[i][j] == 0) {
14                count++;
15                j--;
16            }
17
18            endZeros[i] = count;
19        }
20
21        int steps = 0;
22
23        for(int i = 0; i < n; i++) {
24            
25            int need = n - i - 1;
26
27            int j = i;
28
29            while(j < n && endZeros[j] < need) {
30                j++;
31            }
32
33            if(j == n) {
34                return -1;
35            }
36
37            steps += j-i;
38
39            while(j > i) {
40                swap(endZeros[j], endZeros[j-1]);
41                j--;
42            }
43
44        }
45
46        return steps;
47        
48    }
49};