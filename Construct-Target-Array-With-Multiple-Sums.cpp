1class Solution {
2public:
3    bool isPossible(vector<int>& target) {
4        priority_queue<long long> pq;
5        long long total = 0;
6
7        for (int x : target) {
8            pq.push(x);
9            total += x;
10        }
11
12        while (pq.top() != 1) {
13            long long maxVal = pq.top(); pq.pop();
14            long long rest = total - maxVal;
15
16            if (rest == 0 || maxVal <= rest)
17                return false;
18
19            long long prev = maxVal % rest;
20            if (prev == 0) prev = rest;
21
22            total = rest + prev;
23            pq.push(prev);
24        }
25
26        return true;
27    }
28};
29