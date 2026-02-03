1class Solution {
2public:
3    bool isTrionic(vector<int>& n) {
4        int phase = 0;
5
6        for (int i = 0; i < n.size() - 1; i++) {
7            int diff = n[i] - n[i + 1];
8            if (diff == 0)  return false;
9
10            if (phase == 0) {
11                if (diff < 0) phase = 1;
12                else return false;
13            }
14            else if (phase == 1) {
15                if (diff > 0) phase = 2;
16            }
17            else if (phase == 2) {
18                if (diff < 0) phase = 3;
19            }
20            else { 
21                if (diff > 0) return false;
22            }
23        }
24
25        return phase == 3;
26    }
27};