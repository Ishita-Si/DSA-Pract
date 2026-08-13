class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sumEv = 0;
        int sumOdd = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(i % 2 == 0) sumEv += nums[i];
            else sumOdd += nums[i];
        }

        return sumEv - sumOdd;
    }
};