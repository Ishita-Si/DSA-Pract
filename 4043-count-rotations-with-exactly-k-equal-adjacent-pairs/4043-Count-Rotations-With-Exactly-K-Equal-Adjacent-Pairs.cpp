class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        vector<int> match(2*n-1, 0);
        string t = s+s;

        for(int i = 0; i < 2*n -1; i++){
            if(t[i] == t[i+1]) match[i] = 1;
        }

        int count = 0;
        int ans = 0;
        int l = 0;
        
        int r = n - 2; 

        for(int i = 0; i < n-1; i++){
            if(match[i] == 1) ans += 1;
        }

        if(ans == k) count++;

        while(r < 2*n - 3){
            ans -= match[l];
            l++;
            
            r++;
            ans += match[r];
            
            if(ans == k) count++;       
        }

        return count;
    }
};
