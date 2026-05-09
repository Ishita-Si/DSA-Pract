1class Solution {
2public:
3    int totalFruit(vector<int>& fruits) {
4        int n = fruits.size();
5        int maxLen = 0;
6        int l = 0, r = 0;
7        
8        map<int,int> maps;
9
10        while(r < n){
11            maps[fruits[r]]++;
12            if(maps.size() > 2){
13                while(maps.size() > 2){
14                    maps[fruits[l]]--;
15                    if(maps[fruits[l]] == 0) maps.erase(fruits[l]);
16                    l++;
17                }
18            }
19            if(maps.size() <= 2){
20                maxLen = max(maxLen , r-l+1);
21            }
22            r++;
23        }
24        return maxLen;
25    }
26};