1class Solution {
2public:
3    int minPairSum(vector<int>& nums) {
4        int minSum = INT_MAX;
5        int index = -1;
6
7        for (int i = 0; i < nums.size() - 1; i++) {
8            if (nums[i] + nums[i + 1] < minSum) {
9                index = i;
10                minSum = nums[i] + nums[i + 1];
11            }
12        }
13        return index;
14    }
15    int minimumPairRemoval(vector<int>& nums) {
16        int count = 0;
17        while (!is_sorted(begin(nums), end(nums))) {
18            int index = minPairSum(nums);
19            nums[index] = nums[index] + nums[index+1];
20            nums.erase(begin(nums) + index + 1);
21            count++;
22        }
23
24        return count;
25    }
26};