1class Solution {
2public:
3    vector<int> searchRange(vector<int>& nums, int target) {
4        int first = findFirst(nums, target);
5        if (first == -1) return {-1, -1};
6
7        int last = findLast(nums, target);
8        return {first, last};
9    }
10
11private:
12    int findFirst(vector<int>& nums, int target) {
13        int left = 0, right = nums.size() - 1;
14        int ans = -1;
15
16        while (left <= right) {
17            int mid = left + (right - left) / 2;
18
19            if (nums[mid] == target) {
20                ans = mid;
21                right = mid - 1;   
22            }
23            else if (nums[mid] < target) {
24                left = mid + 1;
25            }
26            else {
27                right = mid - 1;
28            }
29        }
30        return ans;
31    }
32
33    int findLast(vector<int>& nums, int target) {
34        int left = 0, right = nums.size() - 1;
35        int ans = -1;
36
37        while (left <= right) {
38            int mid = left + (right - left) / 2;
39
40            if (nums[mid] == target) {
41                ans = mid;
42                left = mid + 1;   
43            }
44            else if (nums[mid] < target) {
45                left = mid + 1;
46            }
47            else {
48                right = mid - 1;
49            }
50        }
51        return ans;
52    }
53};
54