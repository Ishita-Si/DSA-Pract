1class Solution {
2public:
3    int minSubarray(vector<int>& nums, int p) {
4        long long total = 0;
5        for (int x : nums) total += x;
6
7        int rem = total % p;
8        if (rem == 0) return 0;
9
10        unordered_map<int, int> mp;
11        mp[0] = -1;  
12
13        long long prefix = 0;
14        int ans = nums.size();
15
16        for (int i = 0; i < nums.size(); i++) {
17            prefix += nums[i];
18            int currRem = prefix % p;
19
20            int need = (currRem - rem + p) % p;
21
22            if (mp.count(need)) {
23                ans = min(ans, i - mp[need]);
24            }
25
26            mp[currRem] = i;
27        }
28
29        return ans == nums.size() ? -1 : ans;
30    }
31};
32