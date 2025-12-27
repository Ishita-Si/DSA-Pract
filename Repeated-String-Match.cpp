1class Solution {
2public:
3    int repeatedStringMatch(string a, string b) {
4        string repeated = "";
5        int count = 0;
6
7        while (repeated.size() < b.size()) {
8            repeated += a;
9            count++;
10        }
11
12        if (repeated.find(b) != string::npos)
13            return count;
14
15        repeated += a;
16        count++;
17
18        if (repeated.find(b) != string::npos)
19            return count;
20
21        return -1;
22        }
23    };