1class Solution {
2public:
3    vector<int> constructTransformedArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> arr(n);
6
7        for (int i = 0; i < n; i++) {
8            if (nums[i] == 0) {
9                arr[i] = nums[i];
10            } else {
11                int idx = (i + nums[i]) % n;
12                if (idx < 0) idx += n;   
13                arr[i] = nums[idx];
14            }
15        }
16        return arr;
17    }
18};