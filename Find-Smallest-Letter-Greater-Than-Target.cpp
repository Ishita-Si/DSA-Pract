1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        int low = 0;
5        int high = letters.size() - 1;
6
7        if (target >= letters.back()) {
8            return letters[0];
9        }
10
11        while (low <= high) {
12            int mid = low + (high - low) / 2;
13
14            if (letters[mid] > target) {
15                high = mid - 1;
16            } else {
17                low = mid + 1;
18            }
19        }
20        return letters[low];
21    }
22};