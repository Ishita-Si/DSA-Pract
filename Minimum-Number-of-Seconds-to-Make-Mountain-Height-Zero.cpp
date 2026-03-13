1class Solution {
2public:
3    typedef long long ll;
4
5    bool Check(ll mid, vector<int>& workerTimes, int mH) {
6        ll h = 0;
7
8        for(int &t : workerTimes) {
9            h += (ll)(sqrt(2.0 * mid/t + 0.25) - 0.5);
10
11            if(h >= mH) {
12                return true;
13            }
14        }
15
16        return h >= mH;
17    }
18
19    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
20        int maxTime = *max_element(begin(workerTimes), end(workerTimes));
21        ll l = 1;
22        ll r = (ll)maxTime * mountainHeight * (mountainHeight+1)/2;
23
24        ll result = 0;
25
26        while(l <= r) {
27            ll mid = l + (r-l)/2;
28
29            if(Check(mid, workerTimes, mountainHeight)) {
30                result = mid;
31                r = mid-1;
32            } else {
33                l = mid+1;
34            }
35        }
36
37        return result;
38    }
39};