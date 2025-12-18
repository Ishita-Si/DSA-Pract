1class Solution {
2public:
3    int minDays(vector<int>& bloomDay, int m, int k) {
4        long long totalFlowers = (long long)m * k;
5        if (totalFlowers > bloomDay.size())
6            return -1; 
7
8        int left = *min_element(bloomDay.begin(), bloomDay.end());
9        int right = *max_element(bloomDay.begin(), bloomDay.end());
10        int ans = -1;
11
12        while (left <= right) {
13            int mid = left + (right - left) / 2;
14
15            if (canMake(bloomDay, m, k, mid)) {
16                ans = mid;       
17                right = mid - 1;  
18            } else {
19                left = mid + 1;  
20            }
21        }
22        return ans;
23    }
24
25private:
26    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
27        int bouquets = 0;
28        int flowers = 0;
29
30        for (int d : bloomDay) {
31            if (d <= day) {
32                flowers++;
33                if (flowers == k) {
34                    bouquets++;
35                    flowers = 0;
36                }
37            } else {
38                flowers = 0;
39            }
40        }
41        return bouquets >= m;
42    }
43};
44