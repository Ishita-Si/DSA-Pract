1class Solution {
2public:
3    string licenseKeyFormatting(string s, int k) {
4        string temp = "";
5        for(char ch : s){
6            if(ch != '-'){
7                temp += toupper(ch);
8            }
9        }
10
11        string ans ="";
12        int count = 0;
13        for(int i = temp.size()-1; i >= 0; i--){
14            ans.push_back(temp[i]);
15            count++;
16
17            if(count == k && i != 0){
18                ans.push_back('-');
19                count = 0;
20            }
21        }
22        reverse(ans.begin(),ans.end());
23        return ans;
24    }
25};