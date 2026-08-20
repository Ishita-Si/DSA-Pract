class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr1, arr2;
        int size1 = 1;
        int size2 = 1;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2; i < n; i++){
            if(arr1[size1 - 1] > arr2[size2 - 1]){
                arr1.push_back(nums[i]);
                size1++;
            }else{
                arr2.push_back(nums[i]);
                size2++;
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};