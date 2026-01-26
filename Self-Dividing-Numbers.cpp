1class Solution {
2public:
3    vector<int> selfDividingNumbers(int left, int right) {
4        vector<int> ans;
5
6        for (int num = left; num <= right; num++) {
7            int temp = num;
8            bool ok = true;
9
10            while (temp > 0) {
11                int digit = temp % 10;
12                if (digit == 0 || num % digit != 0) {
13                    ok = false;
14                    break;
15                }
16                temp /= 10;
17            }
18
19            if (ok) ans.push_back(num);
20        }
21        return ans;
22    }
23};