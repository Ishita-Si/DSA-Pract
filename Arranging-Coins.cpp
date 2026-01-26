1class Solution {
2public:
3    int arrangeCoins(int n) {
4        long long a = 0;
5      while(n>=a*(a+1)/2){
6        a++;
7      }
8      return a-1;  
9    }
10};