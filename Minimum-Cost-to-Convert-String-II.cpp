1class Solution {
2public:
3    typedef long long ll;
4    typedef pair<ll, string> P;
5    ll BIG_VALUE = 1e10;
6    unordered_map<string, vector<pair<string, ll>>> adj; //Graph
7
8    //start -> end -> anser
9    unordered_map<string, unordered_map<string, ll>> dijkstraMemo;
10
11    vector<ll> dpMemo;
12
13    string sourceStr;
14    string targetStr;
15    set<int> validLengths;
16    
17    ll dijkstra(string& start, string& end) {
18
19        if(dijkstraMemo[start].count(end)) {
20            return dijkstraMemo[start][end];
21        }
22
23        //{cost, string}
24        priority_queue<P, vector<P>, greater<P>> pq;
25        //vector<int> result(n, INT_MAX)
26        unordered_map<string, ll> result; //source to string ka cost stored
27        result[start] = 0;
28        pq.push({0, start});
29
30        while(!pq.empty()) {
31            ll currCost = pq.top().first;
32            string node = pq.top().second;
33            pq.pop();
34
35            if(node == end) {
36                break;
37            }
38
39            for(auto &edge : adj[node]) {
40                string adjNode = edge.first;
41                ll edgeCost = edge.second;
42
43                if(!result.count(adjNode) || currCost + edgeCost < result[adjNode]) {
44                    result[adjNode] = currCost + edgeCost;
45                    pq.push({currCost+edgeCost, adjNode});
46                }
47            }
48        }
49
50        ll finalCost = result.count(end) ? result[end] : BIG_VALUE;
51
52        return dijkstraMemo[start][end] = finalCost;
53
54    }
55
56    ll solve(int idx) {
57        if(idx >= sourceStr.length())
58            return 0;
59        if(dpMemo[idx] != -1)
60            return dpMemo[idx];
61
62        ll minCost = BIG_VALUE;
63
64        if(sourceStr[idx] == targetStr[idx])
65            minCost = solve(idx+1);
66        
67        for(auto &len : validLengths) {
68            if(idx + len > sourceStr.length()) {
69                break;
70            }
71
72            string srcSub = sourceStr.substr(idx, len);
73            string tgtSub = targetStr.substr(idx, len);
74
75            if(!adj.count(srcSub)) {
76                continue;
77            }
78
79            ll minPathCost = dijkstra(srcSub, tgtSub);
80            if(minPathCost == BIG_VALUE)
81                continue;
82            
83            minCost = min(minCost, minPathCost + solve(idx+len));
84        }
85
86        return dpMemo[idx] = minCost;
87    }
88
89    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
90        sourceStr = source;
91        targetStr = target;
92
93        dpMemo.assign(10001, -1);
94
95        for(int i = 0; i < original.size(); i++) {
96            adj[original[i]].push_back({changed[i], cost[i]});
97        }
98
99        for(auto &s : original) {
100            validLengths.insert(s.length());
101        }
102
103        ll result = solve(0);
104
105        return result == BIG_VALUE ? -1 : result;
106    }
107};