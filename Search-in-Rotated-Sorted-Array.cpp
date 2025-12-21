1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int left = 0, right = nums.size()-1;
5        while(left <= right){
6            int mid = left + (right - left)/2;
7
8            if (nums[mid] == target){
9                return mid;
10            }
11
12            if(nums[left] <= nums[mid]){
13                if(nums[left] <= target && nums[mid] >= target){
14                    right = mid - 1; 
15                }else {
16                    left = mid + 1;
17                }
18            }else{
19                if(nums[mid] <= target && nums[right] >= target){
20                    left = mid + 1; 
21                }else {
22                    right = mid - 1;
23                }
24            }
25        }
26         return -1;
27    }
28};