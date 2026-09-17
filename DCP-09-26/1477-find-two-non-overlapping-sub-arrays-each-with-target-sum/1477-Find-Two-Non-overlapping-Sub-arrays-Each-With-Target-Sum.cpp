class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> min_left(n, INT_MAX);
        
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1; 
        
        int curr = 0;
        int minLen = INT_MAX;
        int result = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            curr += arr[i];
            prefix_map[curr] = i;
            
            if (prefix_map.count(curr - target)) {
                int start_idx = prefix_map[curr - target];
                int curr = i - start_idx;
                minLen = min(minLen, curr);
                
                if (start_idx >= 0 && min_left[start_idx] != INT_MAX) {
                    result = min(result, curr + min_left[start_idx]);
                }
            }
            
            min_left[i] = minLen;
        }
        
        return result == INT_MAX ? -1 : result;
    }
};
