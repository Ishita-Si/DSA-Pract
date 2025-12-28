1class Solution {
2public:
3    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
4        sort(nums1.begin(), nums1.end());
5        sort(nums2.begin(), nums2.end());
6
7        vector<int> ans;
8        int i = 0, j = 0;
9
10        while (i < nums1.size() && j < nums2.size()) {
11            if (nums1[i] == nums2[j]) {
12                if (ans.empty() || ans.back() != nums1[i]) {
13                    ans.push_back(nums1[i]);
14                }
15                i++;
16                j++;
17            }
18            else if (nums1[i] < nums2[j]) {
19                i++;
20            }
21            else {
22                j++;
23            }
24        }
25        return ans;
26    }
27};
28