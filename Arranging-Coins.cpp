1class Solution {
2public:
3    int arrangeCoins(int n) {
4        long long count = 0;
5        long long a = 0;
6      while(n>=a*(a+1)/2){
7        count++;
8        a++;
9      }
10      return count-1;  
11    }
12};