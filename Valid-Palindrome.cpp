1class Solution {
2public:
3    bool isPalindrome(string s) {
4        int i = 0, j = s.size() - 1;
5
6        while (i < j) {
7
8            // skip non-alphanumeric on left
9            while (i < j && !isalnum(s[i])) i++;
10
11            // skip non-alphanumeric on right
12            while (i < j && !isalnum(s[j])) j--;
13
14            // compare after normalizing
15            if (tolower(s[i]) != tolower(s[j]))
16                return false;
17
18            i++;
19            j--;
20        }
21        return true;
22    }
23};