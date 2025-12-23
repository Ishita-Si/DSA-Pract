1class Solution {
2public:
3    int maxTwoEvents(vector<vector<int>>& events) {
4        sort(events.begin(), events.end(),
5             [](auto &a, auto &b) {
6                 return a[0] < b[0];
7             });
8
9        int n = events.size();
10
11        vector<int> suffixMax(n);
12        suffixMax[n - 1] = events[n - 1][2];
13
14        for (int i = n - 2; i >= 0; i--) {
15            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
16        }
17
18        int ans = 0;
19
20        for (int i = 0; i < n; i++) {
21            int start = events[i][0];
22            int end = events[i][1];
23            int value = events[i][2];
24
25            ans = max(ans, value);
26
27            int left = i + 1, right = n - 1;
28            int idx = n;
29
30            while (left <= right) {
31                int mid = (left + right) / 2;
32                if (events[mid][0] >= end + 1) {
33                    idx = mid;
34                    right = mid - 1;
35                } else {
36                    left = mid + 1;
37                }
38            }
39
40            if (idx < n) {
41                ans = max(ans, value + suffixMax[idx]);
42            }
43        }
44
45        return ans;
46    }
47};
48