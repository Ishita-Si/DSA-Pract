1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        priority_queue<int> pq;
5
6        for(int x : nums){
7            pq.push(x);
8        }
9        while(pq.size()>nums.size()-k+1){
10            int x = pq.top();pq.pop();
11        }
12        return pq.empty()?0:pq.top();
13    }
14};