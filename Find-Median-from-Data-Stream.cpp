1class MedianFinder {
2public:
3priority_queue<int> left_maxHeap;
4priority_queue<int,vector<int>,greater<int>> right_minHeap;
5    MedianFinder() {
6        
7    }
8    
9    void addNum(int num) {
10        if(left_maxHeap.empty() || num < left_maxHeap.top()){
11            left_maxHeap.push(num);
12        }else{
13            right_minHeap.push(num);
14        }
15
16        if(abs((int)left_maxHeap.size() - (int)right_minHeap.size()) > 1){
17            right_minHeap.push(left_maxHeap.top());
18            left_maxHeap.pop();
19        }else if(left_maxHeap.size() < right_minHeap.size() ){
20            left_maxHeap.push(right_minHeap.top());
21            right_minHeap.pop();
22        }
23    }
24    
25    double findMedian() {
26        if(left_maxHeap.size() == right_minHeap.size()){
27            double mean = (double)(left_maxHeap.top() + right_minHeap.top())/2;
28            return mean;
29        } 
30
31        return left_maxHeap.top();
32    }
33};
34
35/**
36 * Your MedianFinder object will be instantiated and called as such:
37 * MedianFinder* obj = new MedianFinder();
38 * obj->addNum(num);
39 * double param_2 = obj->findMedian();
40 */