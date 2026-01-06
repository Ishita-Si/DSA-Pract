1class Solution {
2public:
3    string multiply(string num1, string num2) {
4        if (num1 == "0" || num2 == "0") return "0";
5
6        int n = num1.size(), m = num2.size();
7        vector<int> res(n + m, 0);
8
9        for (int i = n - 1; i >= 0; i--) {
10            for (int j = m - 1; j >= 0; j--) {
11                int mul = (num1[i] - '0') * (num2[j] - '0');
12                int sum = mul + res[i + j + 1];
13
14                res[i + j + 1] = sum % 10;      
15                res[i + j] += sum / 10;         
16            }
17        }
18
19        string ans = "";
20        int i = 0;
21        while (i < res.size() && res[i] == 0) i++;
22        for (; i < res.size(); i++)
23            ans += (res[i] + '0');
24
25        return ans;
26    }
27};