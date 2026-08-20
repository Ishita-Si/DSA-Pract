class Solution {
public:
    int digitSum(int x){
        int sum = 0;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int max_val[82] = {0}; 
        int maxSum = -1;

        for(int num : nums){
            int dSum = digitSum(num);

            if(max_val[dSum] > 0){
                maxSum = max(maxSum, num + max_val[dSum]);
            }

            max_val[dSum] = max(max_val[dSum], num);
        }
        return maxSum;
    }
};