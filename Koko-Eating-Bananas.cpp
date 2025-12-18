1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4    int left = 1, right = *max_element(piles.begin(), piles.end());
5
6    while (left < right) {
7        int mid = left + (right - left) / 2;
8
9        long long hours = 0;
10        for (int pile : piles)
11            hours += (pile + mid - 1) / mid;
12
13        if (hours <= h)
14            right = mid;     
15        else
16            left = mid + 1;  
17    }
18    return left;
19}
20};