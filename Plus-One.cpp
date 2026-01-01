1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4        int n = digits.size();
5        
6        for (int i = n - 1; i >= 0; i--) {
7            if (digits[i] < 9) {
8                digits[i]++;        
9                return digits;
10            }
11            digits[i] = 0;         
12        }
13        
14        digits.insert(digits.begin(), 1);
15        return digits;
16    }
17};
18