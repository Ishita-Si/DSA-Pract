class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int maxElm = 0;

        for(int x : nums){
            freq[x]++;
            maxElm = max(maxElm, x);
        
        }

        if(k == n) return maxElm;
        if(k == 1){
            int maxEl = -1;
            for(int x : nums){
                if(freq[x] == 1) maxEl = max(maxEl, x);
            }

            return maxEl;
        }

        if(freq[nums[0]] == 1 && freq[nums[n-1]] == 1) return max(nums[0],nums[n-1]);
        else if(freq[nums[0]] == 1 && freq[nums[n-1]] != 1) return nums[0];
        else if(freq[nums[0]] != 1 && freq[nums[n-1]] == 1) return nums[n-1];
        else return -1;
    }
};