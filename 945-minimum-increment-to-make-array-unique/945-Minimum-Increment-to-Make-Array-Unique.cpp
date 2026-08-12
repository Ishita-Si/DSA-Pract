class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int cnt = 0;
        int next = 0;

        for (int x : nums) {
            if (x < next) {
                cnt += next - x;
                x = next;
            }

            next = x + 1;
        }

        return cnt;
    }
};