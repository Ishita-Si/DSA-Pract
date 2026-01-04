1class Solution {
2public:
3    vector<int> beautifulArray(int n) {
4        vector<int> res = {1};
5
6        while (res.size() < n) {
7            vector<int> temp;
8            for (int x : res) {
9                if (2*x - 1 <= n)
10                    temp.push_back(2*x - 1);
11            }
12            for (int x : res) {
13                if (2*x <= n)
14                    temp.push_back(2*x);
15            }
16            res = temp;
17        }
18        return res;
19    }
20};