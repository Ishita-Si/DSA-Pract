1class Solution {
2public:
3    struct Pair {
4        int x;
5        long long c;
6        Pair(int x, long long c) : x(x), c(c) {}
7    };
8
9    int minCost(int n, vector<vector<int>>& edges) {
10        vector<vector<pair<int,int>>> graph(n), rev(n);
11
12        for (auto &e : edges) {
13            graph[e[0]].push_back({e[1], e[2]});
14            rev[e[1]].push_back({e[0], 2 * e[2]});
15        }
16
17        vector<long long> dist(n, LLONG_MAX);
18        dist[0] = 0;
19
20        priority_queue<pair<long long,int>,
21                       vector<pair<long long,int>>,
22                       greater<pair<long long,int>>> pq;
23
24        pq.push({0, 0});
25
26        while (!pq.empty()) {
27            auto [cost, u] = pq.top();
28            pq.pop();
29
30            if (cost > dist[u]) continue;
31            if (u == n - 1) return (int)dist[u];
32
33            for (auto &[v, w] : graph[u]) {
34                if (dist[u] + w < dist[v]) {
35                    dist[v] = dist[u] + w;
36                    pq.push({dist[v], v});
37                }
38            }
39
40            for (auto &[v, w] : rev[u]) {
41                if (dist[u] + w < dist[v]) {
42                    dist[v] = dist[u] + w;
43                    pq.push({dist[v], v});
44                }
45            }
46        }
47        return -1;
48    }
49};