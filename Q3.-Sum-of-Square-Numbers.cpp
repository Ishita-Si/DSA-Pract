1class Solution {
2public:
3    bool judgeSquareSum(int c) {
4        long long left = 0;
5        long long right = sqrt(c);
6
7        while (left <= right) {
8            long long sum = left * left + right * right;
9
10            if (sum == c)
11                return true;
12            else if (sum < c)
13                left++;
14            else
15                right--;
16        }
17        return false;
18    }
19};