1class Solution {
2public:
3    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
4        hFences.push_back(1);
5        hFences.push_back(m);
6        vFences.push_back(1);
7        vFences.push_back(n);
8
9        sort(hFences.begin(), hFences.end());
10        sort(vFences.begin(), vFences.end());
11
12        unordered_set<int> hDiff, vDiff;
13
14        for (int i = 0; i < hFences.size(); i++) {
15            for (int j = i + 1; j < hFences.size(); j++) {
16                hDiff.insert(hFences[j] - hFences[i]);
17            }
18        }
19
20        for (int i = 0; i < vFences.size(); i++) {
21            for (int j = i + 1; j < vFences.size(); j++) {
22                vDiff.insert(vFences[j] - vFences[i]);
23            }
24        }
25
26        int maxSide = 0;
27        for (int d : hDiff) {
28            if (vDiff.count(d)) {
29                maxSide = max(maxSide, d);
30            }
31        }
32
33        if (maxSide == 0) return -1;
34
35        long long MOD = 1e9 + 7;
36        return (int)((1LL * maxSide * maxSide) % MOD);
37    }
38};