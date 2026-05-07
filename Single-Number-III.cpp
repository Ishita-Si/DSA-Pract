1class Solution {
2public:
3    vector<int> singleNumber(vector<int>& nums) {
4        long long z = 0;
5
6        for(int num : nums) {
7            z ^= num;
8        }
9
10        int RMB = z & (-z);
11
12        int b1 = 0, b2 = 0;
13
14        for(int num : nums) {
15            if((num & RMB) != 0)
16                b1 ^= num;
17            else
18                b2 ^= num;
19        }
20
21        return {b1, b2};
22    }
23};