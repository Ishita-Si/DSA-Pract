1class Solution {
2public:
3    int countPrimeSetBits(int left, int right) {
4
5        unordered_set<int> primes = {2,3,5,7,11,13,17,19};
6
7        int count = 0;
8
9        for (int i = left; i <= right; i++) {
10            int bits = __builtin_popcount(i);
11
12            if (primes.count(bits))
13                count++;
14        }
15
16        return count;
17    }
18};