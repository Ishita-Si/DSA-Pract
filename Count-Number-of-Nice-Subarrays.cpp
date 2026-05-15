1class Solution { // exactly(k)= atMost(k) − atMost(k−1)
2public:
3    int atMost(vector<int>& nums, int k) {
4        int l = 0;
5        int oddCount = 0;
6        int ans = 0;
7
8        for (int r = 0; r < nums.size(); r++) {
9
10            if (nums[r] % 2 != 0) {
11                oddCount++;
12            }
13
14            while (oddCount > k) {
15
16                if (nums[l] % 2 != 0) {
17                    oddCount--;
18                }
19
20                l++;
21            }
22
23            ans += (r - l + 1); // num of subarrays
24        }
25
26        return ans;
27    }
28
29    int numberOfSubarrays(vector<int>& nums, int k) {
30
31        return atMost(nums, k) - atMost(nums, k - 1);
32    }
33};