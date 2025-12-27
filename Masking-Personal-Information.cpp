1class Solution {
2public:
3    string maskPII(string s) {
4        // EMAIL CASE
5        if (s.find('@') != string::npos) {
6            string res;
7            res += tolower(s[0]);
8            res += "*****";
9
10            int at = s.find('@');
11            res += tolower(s[at - 1]);
12
13            for (int i = at; i < s.size(); i++) {
14                res += tolower(s[i]);
15            }
16            return res;
17        }
18
19        // PHONE CASE
20        string digits = "";
21        for (char c : s) {
22            if (isdigit(c)) digits += c;
23        }
24
25        int n = digits.size();
26        string res = "";
27
28        if (n > 10) {
29            res += "+";
30            res += string(n - 10, '*');
31            res += "-";
32        }
33
34        res += "***-***-";
35        res += digits.substr(n - 4);
36
37        return res;
38    }
39};