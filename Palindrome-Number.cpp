1class Solution {
2public:
3    bool isPalindrome(int x) {
4    if (x < 0) return false;  
5
6    string num = to_string(x);
7    int n = num.size();
8
9    for (int i = 0; i < n / 2; i++) {
10        if (num[i] != num[n - 1 - i]) {
11            return false;
12        }
13    }
14    return true;
15}
16
17};