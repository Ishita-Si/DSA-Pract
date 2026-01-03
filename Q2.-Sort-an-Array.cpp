1class Solution {
2public:
3    vector<int> sortArray(vector<int>& nums) {
4        priority_queue<int, vector<int>, greater<int>> pq;
5        for (int x : nums) {
6            pq.push(x);
7        }
8        vector<int> arr;
9        while (!pq.empty()) {
10            arr.push_back(pq.top());
11            pq.pop();
12        }
13        return arr;
14    }
15};