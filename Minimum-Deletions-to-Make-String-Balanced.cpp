1class Solution {
2public:
3    int minimumDeletions(string s) {
4        int count_b = 0;
5        int deletions = 0;
6        for (char c : s) {
7            if (c == 'b') {
8                count_b++;
9            } else {
10                deletions = min(deletions + 1, count_b);
11            }
12        }
13        return deletions;
14    }
15};