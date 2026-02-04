1class Solution {
2public:
3    typedef long long ll;
4    int n;
5    vector<vector<ll>> memo;
6
7    ll solve(int i, int trend, vector<int>& nums) {
8        if(i == n) {
9            if(trend == 3) {
10                return 0; //no more elements, you reached out of bound
11            } else {
12                return LLONG_MIN/2; //invalid small value
13            }
14        }
15
16        if(memo[i][trend] != LLONG_MIN) {
17            return memo[i][trend];
18        }
19
20        ll take = LLONG_MIN/2;
21        ll skip = LLONG_MIN/2;
22
23        //skip
24        if(trend == 0) {
25            skip = solve(i+1, 0, nums);
26        }
27
28        //i am at trend 3 and i can now end at nums[i]
29        if(trend == 3) {
30            take = nums[i]; //finish it here
31        }
32
33        if(i+1 < n) {
34            int curr = nums[i];
35            int next = nums[i+1];
36
37            if(trend == 0 && next > curr) {
38                take = max(take, curr + solve(i+1, 1, nums));
39            } else if(trend == 1) {
40                if(next > curr) {
41                    take = max(take, curr + solve(i+1, 1, nums));
42                } else if(next < curr) {
43                    take = max(take, curr + solve(i+1, 2, nums));
44                }
45            } else if(trend == 2) {
46                if(next < curr) {
47                    take = max(take, curr + solve(i+1, 2, nums));
48                } else if(next > curr) {
49                    take = max(take, curr + solve(i+1, 3, nums));
50                }
51            } else if(trend == 3 && next > curr) {
52                take = max(take, curr + solve(i+1, 3, nums));
53            }
54        }
55        
56        return memo[i][trend] = max(take, skip);
57    }
58
59    ll maxSumTrionic(vector<int>& nums) {
60        n = nums.size();
61
62        memo.assign(n+1, vector<ll>(4, LLONG_MIN));
63
64        return solve(0, 0, nums); //solve(i, trend = 0)
65    }
66};