1class Solution {
2public:
3    int mySqrt(int x) {
4        if (x < 2) return x;
5
6        int left = 1, right = x / 2;
7        int ans = 0;
8
9        while (left <= right) {
10            int mid = left + (right - left) / 2;
11
12            if (mid <= x / mid) {  
13                ans = mid;
14                left = mid + 1;
15            } else {
16                right = mid - 1;
17            }
18        }
19        return ans;
20    }
21};