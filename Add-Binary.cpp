1class Solution {
2public:
3    string addBinary(string a, string b) {
4        string result = "";
5        int i = a.size() - 1;
6        int j = b.size() - 1;
7        int carry = 0;
8
9        while (i >= 0 || j >= 0 || carry) {
10            int sum = carry;
11            if (i >= 0) sum += a[i--] - '0';
12            if (j >= 0) sum += b[j--] - '0';
13
14            result.push_back((sum % 2) + '0');
15            carry = sum / 2;
16        }
17        reverse(result.begin(), result.end());
18        return result;
19    }
20};