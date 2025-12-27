1class Solution {
2public:
3    int mostBooked(int n, vector<vector<int>>& meetings) {
4        sort(meetings.begin(), meetings.end());
5
6        priority_queue<int, vector<int>, greater<int>> available;
7        for (int i = 0; i < n; i++) {
8            available.push(i);
9        }
10
11        priority_queue<pair<long long, int>,
12            vector<pair<long long, int>>,
13            greater<pair<long long, int>>> busy;
14
15        vector<int> count(n, 0);
16
17        for (auto& m : meetings) {
18            long long start = m[0];
19            long long end = m[1];
20            while (!busy.empty() && busy.top().first <= start) {
21                available.push(busy.top().second);
22                busy.pop();
23            }
24
25            if (!available.empty()) {
26                int room = available.top();
27                available.pop();
28                busy.push({end, room});
29                count[room]++;
30            } else {
31                auto [finishTime, room] = busy.top();
32                busy.pop();
33
34                long long duration = end - start;
35                busy.push({finishTime + duration, room});
36                count[room]++;
37            }
38        }
39
40        int ans = 0;
41        for (int i = 1; i < n; i++) {
42            if (count[i] > count[ans]) {
43                ans = i;
44            }
45        }
46        return ans;
47    }
48};
49