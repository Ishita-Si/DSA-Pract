1class Solution {
2public:
3    vector<string> buildArray(vector<int>& target, int n) {
4       int stream = 1;
5       vector<string> ans;
6       int i = 0;
7       while(i < target.size() && stream <= n){
8            ans.push_back("Push");
9            if(target[i]==stream){
10                i++;
11            }else{
12                ans.push_back("Pop");
13            }
14            stream++;
15       }
16       return ans; 
17    }
18};