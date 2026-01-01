1class Solution {
2public:
3    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
4        vector<vector<int>> ans;
5        sort(arr.begin(), arr.end());
6
7        int minDiff = INT_MAX;
8        for(int i = 0; i< arr.size()-1;i++){
9            int n = arr[i+1]-arr[i];
10            minDiff = min(minDiff , n);
11        }
12        for(int i = 0; i< arr.size()-1;i++){
13            if(arr[i+1]-arr[i] == minDiff){
14                ans.push_back({arr[i],arr[i+1]});
15            }
16        }
17       return ans; 
18    }
19};