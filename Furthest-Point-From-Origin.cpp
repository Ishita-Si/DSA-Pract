1class Solution {
2public:
3    int furthestDistanceFromOrigin(string moves) {
4        int countL = 0;
5        int countR = 0;
6        int count = 0;
7        for (char s : moves) {
8            if (s == 'L')
9                countL++;
10            else if (s == 'R')
11                countR++;
12            else 
13                count++;
14        }
15
16        return abs(countR - countL) + count;
17    }
18};