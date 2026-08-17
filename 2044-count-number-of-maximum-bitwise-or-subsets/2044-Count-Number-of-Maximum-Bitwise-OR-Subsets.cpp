class Solution {
public:
    int countMaxOrSubsets(vector<int>& arr) {
        int k = 0;
        for(int x : arr){
            k |= x;
        }

        int n = arr.size();
        int ans = 0;

        for (int mask = 0; mask < (1 << n); mask++) {

            int OR = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    OR |= arr[i];
                }
            }

            if (OR == k)
                ans++;
        }

        return ans;
    }
};