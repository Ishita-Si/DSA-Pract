1class Solution {
2public:
3    int longestBalanced(vector<int>& nums) {
4        int n = nums.size();
5
6        int maxLen = 0;
7
8        for(int i = 0; i < n; i++) {
9            unordered_set<int> even;
10            unordered_set<int> odd;
11
12            for(int j = i; j < n; j++) {
13                if(nums[j]%2 == 0)
14                    even.insert(nums[j]);
15                else
16                    odd.insert(nums[j]);
17                
18                if(even.size() == odd.size())
19                    maxLen = max(maxLen, j-i+1);
20            }
21        }
22
23        return maxLen;
24    }
25};