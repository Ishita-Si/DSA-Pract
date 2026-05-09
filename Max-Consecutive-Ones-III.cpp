1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int l = 0, r = 0;
5        int len = 0;
6        int zeros = 0;
7        int maxLen = 0;
8        int n = nums.size();
9
10        while(r < n){
11            if(nums[r] == 0) zeros++;
12            if(zeros > k){
13                if(nums[l] == 0) zeros--;
14                l++;
15            }
16            if(zeros <= k){
17                len = r - l + 1;
18                maxLen = max(len, maxLen);
19            } 
20            r++;
21        }
22
23        return maxLen;
24    }
25};