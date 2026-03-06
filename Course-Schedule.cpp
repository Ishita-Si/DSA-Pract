1class Solution {
2public:
3    bool isCycleDFS(int src, vector<bool>& vis, vector<bool>& recPath,
4                    vector<vector<int>>& prereq) {
5        vis[src] = true;
6        recPath[src] = true;
7        for (int i = 0; i < prereq.size(); i++) {
8            int v = prereq[i][0];
9            int u = prereq[i][1];
10
11            if (u == src) {
12                if (!vis[v]) {
13                    if (isCycleDFS(v, vis, recPath, prereq)) {
14                        return true;
15                    }
16                } else if (recPath[v]) {
17                    return true;
18                }
19            }
20        }
21        recPath[src] = false;
22        return false;
23    }
24
25    bool canFinish(int n, vector<vector<int>>& prereq) {
26        vector<bool> vis(n, false);
27        vector<bool> recPath(n, false);
28
29        for (int i = 0; i < n; i++) {
30            if (!vis[i]) {
31                if (isCycleDFS(i, vis, recPath, prereq)) {
32                    return false;
33                }
34            }
35        }
36        return true;
37    }
38};