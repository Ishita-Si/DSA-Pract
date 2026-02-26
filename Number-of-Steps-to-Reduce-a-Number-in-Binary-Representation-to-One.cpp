1class Solution {
2public:
3    int numSteps(string s) {
4        int steps = 0;
5        int carry = 0;
6        for (int i = s.size() - 1; i > 0; i--) {
7            if ((s[i] - '0' + carry) % 2 == 0) {
8                steps += 1;
9            } else {
10                steps += 2;
11                carry = 1;
12            }
13        }
14
15        return steps + carry;
16    }
17};