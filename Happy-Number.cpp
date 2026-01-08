1class Solution {
2public:
3    bool isHappy(int n) {
4        unordered_set<int> seen;
5
6        while (n != 1) {
7            if (seen.count(n)) return false;
8            seen.insert(n);
9
10            int sum = 0;
11            while (n > 0) {
12                int digit = n % 10;
13                sum += digit * digit;
14                n /= 10;
15            }
16            n = sum;
17        }
18        return true;
19    }
20};