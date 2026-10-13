class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        
        long long sum = 0;
        long long sum2 = 0;

        for(int i = 0; i< n; i++){
            arr[i] = abs(nums[i]);
        }

        sort(arr.begin(), arr.end());

        for(int i = 0; i < n / 2; i++){
            sum += arr[i]*arr[i];
        }
        for(int i = n / 2; i < n; i++){
            sum2 += arr[i]*arr[i];
        }

        return sum2 - sum;
    }
};