1class Solution {
2public:
3    int minOperations(string s, int k) {
4        int n=s.size(),z=0;
5        for(auto it:s) if(it=='0') z++;
6        if(z==0) return 0;
7        vector<int>dis(n+1,-1);
8        queue<int>q; dis[z]=0; q.push(z);
9        set<int> unvis[2];
10        for (int i=0;i<=n;i++) if(i!=z) unvis[i%2].insert(i);
11        while(!q.empty()){
12            int a=q.front(); q.pop();
13            int par=(a+k)%2,steps=dis[a];
14            int high=min(k,a),low=max(0,k-(n-a));
15            int minA=a+(k-2*high),maxA=a+(k-2*low);
16            auto it=unvis[par].lower_bound(minA);
17            while(it!=unvis[par].end() && *it<=maxA){
18                int nxt=*it;
19                it=unvis[par].erase(it);
20                dis[nxt]=steps+1;
21                if(nxt==0) return dis[nxt];
22                q.push(nxt);
23            }
24        }
25        return -1;
26    }
27};