1class Solution {
2public:
3    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
4                                       vector<int>& nums2, int k) {
5
6        vector<vector<int>> result;
7        if (nums1.empty() || nums2.empty() || k == 0) return result;
8
9        priority_queue<
10            tuple<int,int,int>,
11            vector<tuple<int,int,int>>,
12            greater<>
13        > pq;
14
15        for (int i = 0; i < nums1.size() && i < k; i++) {
16            pq.push({nums1[i] + nums2[0], i, 0});
17        }
18
19        while (k-- > 0 && !pq.empty()) {
20            auto [sum, i, j] = pq.top();
21            pq.pop();
22
23            result.push_back({nums1[i], nums2[j]});
24
25            if (j + 1 < nums2.size()) {
26                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
27            }
28        }
29
30        return result;
31    }
32};