1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& nums) {
4    int left = 0, right = nums.size() - 1;
5
6    while (left < right) {
7        int mid = left + (right - left) / 2;
8
9        if (mid % 2 == 1)
10            mid--;
11
12        if (nums[mid] == nums[mid + 1]) {
13            left = mid + 2;
14        } else {
15            right = mid;
16        }
17    }
18    return nums[left];
19}
20};