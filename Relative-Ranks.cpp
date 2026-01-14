1class Solution {
2public:
3    vector<string> findRelativeRanks(vector<int>& score) {
4        int n = score.size();
5        vector<string> ans(n);
6        priority_queue<pair<int,int>> pq;
7
8        for (int i = 0; i < n; i++) {
9            pq.push({score[i], i});
10        }
11
12        int rank = 1;
13
14        while (!pq.empty()) {
15            int idx = pq.top().second;
16            pq.pop();
17
18            if (rank == 1)
19                ans[idx] = "Gold Medal";
20            else if (rank == 2)
21                ans[idx] = "Silver Medal";
22            else if (rank == 3)
23                ans[idx] = "Bronze Medal";
24            else
25                ans[idx] = to_string(rank);
26
27            rank++;
28        }
29        return ans;
30    }
31};