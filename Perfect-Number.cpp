1class Solution {
2public:
3    bool checkPerfectNumber(int num) {
4        if (num <= 1)
5            return false;
6
7        int sum = 1;
8
9        for (int i = 2; i * i <= num; i++) {
10            if (num % i == 0) {
11                sum += i;
12                if (i != num / i) {
13                    sum += num / i;
14                }
15            }
16        }
17        return sum == num;
18    }
19};