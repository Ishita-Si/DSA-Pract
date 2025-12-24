1class Solution {
2public:
3    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
4        int count = 0;
5        for(int i = 0; i<apple.size();i++){
6            count += apple[i];
7        }
8        sort(capacity.begin(), capacity.end(), greater<int>());
9        int minBox = 0;
10        int currCap = 0;
11        for(int i = 0; i<capacity.size();i++){
12            currCap += capacity[i];
13            minBox++;
14            if(currCap >= count){
15                return minBox;
16            } 
17        }
18        return minBox;
19    }
20};