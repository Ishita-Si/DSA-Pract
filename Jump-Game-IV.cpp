1class Solution {
2public:
3    int minJumps(vector<int>& arr) {
4
5        int n = arr.size();
6
7        if(n == 1) return 0;
8
9        unordered_map<int, vector<int>> mp;
10
11        for(int i = 0; i < n; i++) {
12            mp[arr[i]].push_back(i);
13        }
14
15        queue<pair<int,int>> q;
16        vector<bool> vis(n, false);
17
18        q.push({0, 0});
19        vis[0] = true;
20
21        while(!q.empty()) {
22
23            auto [idx, steps] = q.front();
24            q.pop();
25
26            if(idx == n - 1)
27                return steps;
28
29            vector<int> next;
30
31            for(int x : mp[arr[idx]]) {
32                next.push_back(x);
33            }
34
35            next.push_back(idx + 1);
36            next.push_back(idx - 1);
37
38            for(int x : next) {
39
40                if(x >= 0 && x < n && !vis[x]) {
41                    vis[x] = true;
42                    q.push({x, steps + 1});
43                }
44            }
45
46            mp[arr[idx]].clear();
47        }
48
49        return -1;
50    }
51};