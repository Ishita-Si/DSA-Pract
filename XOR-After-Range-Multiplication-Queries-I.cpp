1class Solution {
2public:
3    int M = 1e9 + 7;
4    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
5        for(auto &query : queries){
6            int l = query[0];
7            int r = query[1];
8            int k = query[2];
9            int v = query[3];
10
11            while (l <= r){
12                nums[l] = (1LL * nums[l] * v) % M;
13                l += k;
14            }
15        }
16
17        int result = 0;
18        for(int &num: nums){
19            result ^= num;
20        }
21
22        return result;
23    }
24};