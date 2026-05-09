1class Solution {
2public:
3    int totalFruit(vector<int>& fruits) {
4        int n = fruits.size();
5        int maxLen = 0;
6        int l = 0, r = 0;
7
8        map<int, int> maps;
9
10        while (r < n) {
11            maps[fruits[r]]++;
12            if (maps.size() > 2) {
13                maps[fruits[l]]--;
14                if (maps[fruits[l]] == 0)
15                    maps.erase(fruits[l]);
16                l++;
17            }
18            if (maps.size() <= 2) {
19                maxLen = max(maxLen, r - l + 1);
20            }
21            r++;
22        }
23        return maxLen;
24    }
25};