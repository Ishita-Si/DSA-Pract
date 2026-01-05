1class Solution {
2public:
3    bool isPalindrome(string s) {
4        string k = "";
5        for (char c : s) {
6            if (c >= 'a' && c <= 'z') {
7                k.push_back(c);
8            }
9            else if (c >= 'A' && c <= 'Z') {
10                k.push_back(tolower(static_cast<unsigned char>(c)));
11            } 
12            else if (c >= '0' && c <= '9') {
13                k.push_back(c);
14            }
15        }
16        int i = 0, j = k.size() - 1;
17        while (i < j) {
18            if (k[i] != k[j])
19                return false;
20            i++;
21            j--;
22        }
23        return true;
24    }
25};