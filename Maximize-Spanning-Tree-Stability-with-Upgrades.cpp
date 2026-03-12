1class DSU {
2public:
3    vector<int> parent, rank;
4
5    DSU(int n) {
6        parent.resize(n);
7        rank.resize(n, 1);
8
9        for(int i = 0; i < n; i++) {
10            parent[i] = i;
11        }
12    }
13
14    int find (int x) {
15        if (x == parent[x]) 
16            return x;
17
18        return parent[x] = find(parent[x]);
19    }
20
21    bool Union(int x, int y) {
22        int x_parent = find(x);
23        int y_parent = find(y);
24
25        if (x_parent == y_parent) 
26            return false;
27
28        if(rank[x_parent] > rank[y_parent]) {
29            parent[y_parent] = x_parent;
30        } else if(rank[x_parent] < rank[y_parent]) {
31            parent[x_parent] = y_parent;
32        } else {
33            parent[x_parent] = y_parent;
34            rank[y_parent]++;
35        }
36
37        return true;
38    }
39};
40
41class Solution {
42public:
43
44    bool check(int n, vector<vector<int>>& edges, int k, int mid) {
45        DSU dsu(n);
46
47        vector<vector<int>> upgradeCandidates;
48
49        for(auto &edge : edges) {
50            int u = edge[0];
51            int v = edge[1];
52
53            int s = edge[2];
54            int m = edge[3];
55
56            if(m == 1) {
57                if(s < mid) {
58                    return false;
59                }
60
61                dsu.Union(u, v);
62            } else {
63                if(s >= mid) {
64                    dsu.Union(u, v);
65                } else if(2*s >= mid) {
66                    upgradeCandidates.push_back({u, v});
67                }
68            }
69        }
70
71        for(auto &edge : upgradeCandidates) { 
72            int u = edge[0];
73            int v = edge[1];
74
75            if(dsu.find(u) != dsu.find(v)) {
76                if(k <= 0)
77                    return false;
78                
79                dsu.Union(u, v);
80                k--; 
81            }
82        }
83
84
85        int root = dsu.find(0);
86        for(int node = 1; node <= n-1; node++) { 
87            if(dsu.find(node) != root)
88                return false;
89        }
90        return true;
91    }
92
93    int maxStability(int n, vector<vector<int>>& edges, int k) {
94
95        DSU dsu(n);
96        for(auto &edge : edges) {
97            int u = edge[0];
98            int v = edge[1];
99
100            int s = edge[2];
101            int m = edge[3];
102
103            if(m == 1) { 
104                if(dsu.find(u) == dsu.find(v))
105                    return -1;
106                
107                dsu.Union(u, v);
108            }
109        }
110
111
112        int result = -1;
113        int l = 1;
114        int r = 2*1e5;
115
116        while(l <= r) {
117            int mid = l + (r-l)/2;
118
119            if(check(n, edges, k, mid)) {
120                result = mid;
121                l = mid+1;
122            } else {
123                r = mid -1;
124            }
125        }
126
127        return result;
128    }
129};