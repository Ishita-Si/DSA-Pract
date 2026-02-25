1class Solution {
2public:
3    vector<int> sortByBits(vector<int>& arr) {
4        sort(arr.begin(), arr.end(), [](int a, int b) {
5            int countA = __builtin_popcount(a);
6            int countB = __builtin_popcount(b);
7
8            if (countA == countB)
9                return a < b;  
10            return countA < countB;
11        });
12
13        return arr;
14    }
15};