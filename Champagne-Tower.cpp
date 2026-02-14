1class Solution {
2public:
3    double t[101][101];
4    double solve(int poured, int i, int j) {
5        
6        if(i < 0 || j > i || j < 0)
7            return 0.0;
8        
9        if(i == 0 && j == 0)
10            return t[i][j] = poured;
11        
12        if(t[i][j] != -1)
13            return t[i][j];
14        
15        double up_left  = (solve(poured, i - 1, j - 1) - 1) / 2.0;
16        
17        double up_right = (solve(poured, i - 1, j) - 1) / 2.0;
18            
19         if(up_left < 0)
20            up_left = 0.0;
21        
22        if(up_right < 0)
23            up_right = 0.0;
24        
25        return t[i][j] = up_left + up_right;
26    }
27    
28    double champagneTower(int poured, int query_row, int query_glass) {
29        for(int i = 0; i<101; i++) {
30            for(int j = 0; j<101; j++) {
31                t[i][j] = -1;
32            }
33        }
34        
35        return min(1.0, solve(poured, query_row, query_glass));
36    }
37};