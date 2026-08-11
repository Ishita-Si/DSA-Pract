class Solution {
public:
    bool canAliceWin(int n) {
        int m = n - 10;
        int i = 1;
        while(m >= 0){
            m -= 10 - i;
            i++;
        }

        return i % 2 == 0;
    }
};