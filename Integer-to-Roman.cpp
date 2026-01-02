1class Solution {
2public:
3    string intToRoman(int num) {
4         vector<pair<int, string>> val = {
5            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
6            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
7            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
8        };
9
10        string ans = "";
11
12        for (auto &p : val) {
13            while (num >= p.first) {
14                ans += p.second;
15                num -= p.first;
16            }
17        }
18        return ans;
19    }
20};