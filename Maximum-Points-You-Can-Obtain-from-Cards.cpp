1class Solution {
2public:
3    int maxScore(vector<int>& cardPoints, int k) {
4        int leftSum = 0 , r = cardPoints.size() - 1;
5        int maxSum = 0 , rightSum = 0;
6
7        for(int i = 0; i < k; i++){
8            leftSum += cardPoints[i];
9            maxSum = leftSum;
10        }
11        
12        for(int i = k-1 ; i >= 0; i--){
13            leftSum -= cardPoints[i];
14            rightSum += cardPoints[r];
15            r -= 1;
16
17            maxSum = max(maxSum , leftSum + rightSum);
18        }
19    return maxSum;
20    }
21};