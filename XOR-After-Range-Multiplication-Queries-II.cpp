1class Solution {
2public:
3int M = 1e9+7;
4// difference array technique , Square root decompostion technique.
5// fermat's little theorem : when(a/b)%M do like (a*1/b)%M = a*pow(b,M-2)%M , binary exponentiation.
6
7    long long power(long long a, long long b){
8        if(b == 0) return 1;
9        long long half = power(a,b/2);
10        long long result = (half * half) % M;
11
12        if(b % 2 == 1){
13            result = ( result * a) % M;
14        }
15
16        return result;
17    }
18    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
19        int n = nums.size();
20        int blockSize = ceil(sqrt(n));
21
22        unordered_map<int, vector<vector<int>>> smallKMap;
23
24        for(auto &query : queries) {
25            int L = query[0];
26            int R = query[1];
27            int K = query[2];
28            int V = query[3];
29
30            if(K >= blockSize) {
31                for(int i = L; i<= R; i+=K) {
32                    nums[i] = (1LL * nums[i] * V) % M;
33                }
34            } else { //K < blockSize
35                smallKMap[K].push_back(query);
36            }
37        }
38
39        for(auto& [K, allQueries] : smallKMap) {
40            vector<long long> diff(n, 1);
41
42            for(auto& query : allQueries) {
43                int L = query[0];
44                int R = query[1];
45                int V = query[3];
46
47                diff[L] = (diff[L] * V) % M;
48
49                int steps = (R - L)/K;
50                int next  = L + (steps+1)*K;
51
52                if(next < n)
53                    diff[next] = (diff[next] * power(V, M-2)) % M;
54            }
55
56            //Cumulative product
57            for(int i = 0; i < n; i++) {
58                if(i-K >= 0)
59                    diff[i] = (diff[i] * diff[i-K]) % M;
60            }
61
62            //Apply diff to nums
63            for(int i = 0; i < n; i++) {
64                nums[i] = (1LL * nums[i] * diff[i]) % M;
65            }
66        }
67
68        int result = 0;
69        for(int &num : nums) {
70            result = (result ^ num);
71        }
72
73        return result;
74    }
75};
76