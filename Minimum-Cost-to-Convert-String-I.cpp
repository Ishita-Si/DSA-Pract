1class Solution {
2public:
3    long long minimumCost(string source, string target,
4                          vector<char>& original,
5                          vector<char>& changed,
6                          vector<int>& cost) {
7        const long long INF = LLONG_MAX / 4;
8        vector<vector<long long>> d(26, vector<long long>(26, INF));
9
10        for (int i = 0; i < 26; i++) d[i][i] = 0;
11
12        for (int i = 0; i < cost.size(); i++) {
13            int u = original[i] - 'a';
14            int v = changed[i] - 'a';
15            d[u][v] = min(d[u][v], (long long)cost[i]);
16        }
17
18        for (int k = 0; k < 26; k++) {
19            for (int i = 0; i < 26; i++) {
20                for (int j = 0; j < 26; j++) {
21                    if (d[i][k] < INF && d[k][j] < INF) {
22                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
23                    }
24                }
25            }
26        }
27
28        long long total = 0;
29        for (int i = 0; i < source.size(); i++) {
30            int s = source[i] - 'a';
31            int t = target[i] - 'a';
32            if (s != t) {
33                if (d[s][t] >= INF) return -1;
34                total += d[s][t];
35            }
36        }
37        return total;
38    }
39};