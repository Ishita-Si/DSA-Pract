1class Solution {
2public:
3    int findNthDigit(int n) {
4        long long digitLen = 1;
5        long long count = 9;
6        long long start = 1;
7
8        while (n > digitLen * count) {
9            n -= digitLen * count;
10            digitLen++;
11            count *= 10;
12            start *= 10;
13        }
14        start += (n - 1) / digitLen;
15
16        string num = to_string(start);
17        return num[(n - 1) % digitLen] - '0';
18    }
19};
20