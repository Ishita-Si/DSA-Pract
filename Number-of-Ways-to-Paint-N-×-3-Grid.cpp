1class Solution {
2    int MOD = 1000000007;
3public:
4    int numOfWays(int n) {
5        if(n==0) return 0;
6        long two = 6;
7        long three = 6;
8        n--;
9        while(n>0){
10            long nextTwo = (3*two + 2*three)%MOD;
11            three = (2*two + 2*three)%MOD;
12            two = nextTwo;
13            n--;
14        }
15        return (int)(two+three)%MOD;
16    }
17};