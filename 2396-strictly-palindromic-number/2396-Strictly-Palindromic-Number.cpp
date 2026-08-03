class Solution {
public:
    bool isPalindrome(string g){
        int n = g.size();
        for(int i = 0; i < n/2; i++){
            if(g[i] != g[n-i-1]) return false;
        }
        return true;
    }
    bool isStrictlyPalindromic(int t) {
        for(int i = 2; i <= t-2 ; ++i){
            string ans = "";
            int n = t;
            while (n > 0) {
                int rem = n % i;

                if (rem < 10)
                    ans += char(rem + '0');
                else
                    ans += char(rem - 10 + 'A');

                n /= i;
            }

            reverse(ans.begin(), ans.end());
            if(!isPalindrome(ans)) return false;
        }
        return true;
    }
};