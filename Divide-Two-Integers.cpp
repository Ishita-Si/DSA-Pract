1class Solution {
2public:
3    int divide(int dividend, int divisor) {
4        
5        if (dividend == INT_MIN && divisor == -1)
6            return INT_MAX;
7
8        long long n = abs((long long)dividend);
9        long long d = abs((long long)divisor);
10
11        long long ans = 0;
12
13        while (n >= d) {
14
15            long long cnt = 0;
16
17            while (n >= (d << (cnt + 1))) {
18                cnt++;
19            }
20
21            ans += (1LL << cnt);
22            n -= (d << cnt);
23        }
24
25        if ((dividend < 0) ^ (divisor < 0))
26            ans = -ans;
27
28        return (int)ans;
29    }
30};