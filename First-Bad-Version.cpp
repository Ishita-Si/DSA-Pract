1// The API isBadVersion is defined for you.
2// bool isBadVersion(int version);
3
4class Solution {
5public:
6    int firstBadVersion(int n) {
7        int low = 1, high = n;
8        
9        while (low < high) {
10            int mid = low + (high - low) / 2;
11            
12            if (isBadVersion(mid)) {
13                high = mid;     
14            } else {
15                low = mid + 1;   
16            }
17        }
18        
19        return low; 
20    }
21};
22