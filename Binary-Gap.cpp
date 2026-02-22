1class Solution {
2public:
3    int binaryGap(int n) {
4        int last = -1;
5        int maxDist = 0;
6        int position = 0;
7
8        while (n > 0) {
9            if (n & 1) {
10                if (last != -1) {
11                    maxDist = max(maxDist, position - last);
12                }
13                last = position;
14            }
15            n >>= 1;
16            position++;
17        }
18        return maxDist;
19    }
20};