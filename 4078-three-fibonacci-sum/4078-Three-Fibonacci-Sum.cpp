class Solution {
public:
    bool threeFibonacciSum(int n) {
        if (n < 2) return false;
        
        if (n % 2 != 0) return false;
        
        int target = n / 2;
        
        long long a = 1;
        long long b = 1;
        
        while (a <= target) {
            if (a == target) {
                return true;
            }
            long long next = a + b;
            a = b;
            b = next;
        }
        
        return false;
    }
};
