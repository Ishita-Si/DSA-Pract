1class Solution {
2public:
3    int sumFourDivisors(vector<int>& nums) {
4        int totalSum = 0;
5
6        for (int x : nums) {
7            int divCount = 0;
8            int divSum = 0;
9
10            for (int i = 1; i * i <= x; i++) {
11                if (x % i == 0) {
12                    divCount++;
13                    divSum += i;
14
15                    if (i != x / i) {
16                        divCount++;
17                        divSum += x / i;
18                    }
19
20                    if (divCount > 4)
21                        break;
22                }
23            }
24
25            if (divCount == 4)
26                totalSum += divSum;
27        }
28        return totalSum;
29    }
30};