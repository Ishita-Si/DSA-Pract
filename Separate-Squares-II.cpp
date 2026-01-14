1class Solution {
2public:
3    struct Event {
4        double y;
5        int type;
6        int x1, x2;
7    };
8
9    double separateSquares(vector<vector<int>>& squares) {
10        vector<Event> events;
11        set<int> xs;
12
13        for (auto &sq : squares) {
14            int x = sq[0], y = sq[1], s = sq[2];
15            events.push_back({(double)y, 1, x, x + s});
16            events.push_back({(double)y + s, -1, x, x + s});
17            xs.insert(x);
18            xs.insert(x + s);
19        }
20
21        vector<int> x(xs.begin(), xs.end());
22        int n = x.size();
23
24        sort(events.begin(), events.end(),
25             [](const Event &a, const Event &b) { return a.y < b.y; });
26
27        vector<int> cover(4 * n, 0);
28        vector<double> coveredLen(4 * n, 0.0);
29
30        double totalArea = 0.0;
31        double prevY = events[0].y;
32        vector<array<double, 3>> parts;
33
34        int i = 0;
35        while (i < events.size()) {
36            double currY = events[i].y;
37
38            if (currY > prevY) {
39                double h = currY - prevY;
40                double w = coveredLen[1];
41                totalArea += w * h;
42                parts.push_back({prevY, currY, w});
43                prevY = currY;
44            }
45
46            while (i < events.size() && events[i].y == currY) {
47                int l = lower_bound(x.begin(), x.end(), events[i].x1) - x.begin();
48                int r = lower_bound(x.begin(), x.end(), events[i].x2) - x.begin();
49                update(1, 0, n, l, r, events[i].type, x, cover, coveredLen);
50                i++;
51            }
52        }
53
54        double half = totalArea / 2.0;
55        double acc = 0.0;
56
57        for (auto &p : parts) {
58            double y1 = p[0], y2 = p[1], w = p[2];
59            double area = w * (y2 - y1);
60            if (acc + area >= half) {
61                return y1 + (half - acc) / w;
62            }
63            acc += area;
64        }
65
66        return prevY;
67    }
68
69    void update(int node, int l, int r, int ql, int qr, int val,
70                vector<int>& x, vector<int>& cover, vector<double>& coveredLen) {
71        if (qr <= l || r <= ql) return;
72
73        if (ql <= l && r <= qr) {
74            cover[node] += val;
75        } else {
76            int mid = (l + r) / 2;
77            update(node * 2, l, mid, ql, qr, val, x, cover, coveredLen);
78            update(node * 2 + 1, mid, r, ql, qr, val, x, cover, coveredLen);
79        }
80
81        if (cover[node] > 0) {
82            coveredLen[node] = x[r] - x[l];
83        } else {
84            if (r - l == 1) coveredLen[node] = 0;
85            else coveredLen[node] = coveredLen[node * 2] + coveredLen[node * 2 + 1];
86        }
87    }
88};