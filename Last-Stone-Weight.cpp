1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        priority_queue<int> pq;
5
6        for(int x : stones){
7            pq.push(x);
8        }
9        while(pq.size()>1){
10            int y = pq.top(); pq.pop();
11            int x = pq.top(); pq.pop();
12
13            if(y != x){
14                pq.push(y-x);
15            }
16        }
17        return pq.empty()? 0:pq.top();
18    }
19};