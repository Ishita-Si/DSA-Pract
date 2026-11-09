class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int i = 0;
        int j = 1;
        string mini = to_string(nums[i]) + to_string(nums[j]);

        while(j < nums.size()){
            string t = to_string(nums[i]) + to_string(nums[j]);
            i += 2;
            j += 2;

            if(stoi(t) < stoi(mini)){
                mini = t;
            }
        }

        return stoi(mini);
    }
};