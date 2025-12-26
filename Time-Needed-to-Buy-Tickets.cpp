1class Solution {
2public:
3    int timeRequiredToBuy(vector<int>& tickets, int k) {
4        queue<int> q;
5        int time = 0;
6        for (int i = 0; i < tickets.size(); i++) {
7            q.push(i);
8        }
9
10        while (!q.empty()) {
11            int idx = q.front();
12            q.pop();
13            tickets[idx]--;
14            time++;
15
16            if (tickets[idx] > 0) {
17                q.push(idx);
18            } 
19            else if (idx == k) {
20                break;
21            }
22        }
23
24        return time;
25    }
26};
27