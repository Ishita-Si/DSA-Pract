1class Solution {
2public:
3    string addStrings(string num1, string num2) {
4        int i = num1.size() - 1;
5        int j = num2.size() - 1;
6        int carry = 0;
7        string result = "";
8
9        while (i >= 0 || j >= 0 || carry) {
10            int sum = carry;
11
12            if (i >= 0) sum += num1[i--] - '0';
13            if (j >= 0) sum += num2[j--] - '0';
14
15            result.push_back((sum % 10) + '0');
16            carry = sum / 10;
17        }
18
19        reverse(result.begin(), result.end());
20        return result;
21    }
22};