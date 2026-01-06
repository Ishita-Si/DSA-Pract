1class Solution {
2public:
3    string sortSentence(string s) {
4        vector<string> words;
5        string temp = "";
6        for (char c : s) {
7            if (c == ' ') {
8                words.push_back(temp);
9                temp = "";
10            } else {
11                temp += c;
12            }
13        }
14        words.push_back(temp);
15
16        vector<string> res(words.size());
17
18        for (string w : words) {
19            int pos = w.back() - '0' - 1;  
20            w.pop_back();                  
21            res[pos] = w;
22        }
23        string ans = "";
24        for (int i = 0; i < res.size(); i++) {
25            ans += res[i];
26            if (i != res.size() - 1) ans += " ";
27        }
28
29        return ans;
30    }
31};