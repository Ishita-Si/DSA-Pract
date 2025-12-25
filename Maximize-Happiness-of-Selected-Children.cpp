1class Solution {
2public:
3    long long maximumHappinessSum(vector<int>& hap, int k) {
4        sort(hap.begin(), hap.end());
5
6        long long sum = 0;
7        int n = hap.size();
8
9        for (int i = 0; i < k; i++) {
10            int curr = hap[n - 1 - i] - i;
11            if (curr <= 0) break;
12            sum += curr;
13        }
14
15        return sum;
16    }
17};
18