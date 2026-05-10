1class Solution {
2public:
3    vector<int> majorityElement(vector<int>& nums) {
4        int cnt1 = 0, cnt2 = 0;
5        int el1 = INT_MIN, el2 = INT_MIN;
6
7        for(int x : nums){
8
9            if(cnt1 == 0 && x != el2){
10                el1 = x;
11                cnt1 = 1;
12            }
13            else if(cnt2 == 0 && x != el1){
14                el2 = x;
15                cnt2 = 1;
16            }
17            else if(x == el1) cnt1++;
18            else if(x == el2) cnt2++;
19            else{
20                cnt1--;
21                cnt2--;
22            }
23        }
24
25        cnt1 = 0;
26        cnt2 = 0;
27
28        for(int x : nums){//real freq
29            if(x == el1) cnt1++;
30            else if(x == el2) cnt2++;
31        }
32
33        vector<int> ans;
34
35        if(cnt1 > nums.size()/3) ans.push_back(el1);
36        if(cnt2 > nums.size()/3) ans.push_back(el2);
37
38        return ans;
39    }
40};