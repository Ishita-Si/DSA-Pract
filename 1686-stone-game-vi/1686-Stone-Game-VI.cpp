class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < n; i++){
            pq.push({aliceValues[i] + bobValues[i], i});
        }

        int alice = 0;
        int bob = 0;
        bool flag = true;

        while(!pq.empty()){
            int idx = pq.top().second; 
            pq.pop();

            if(flag){
                alice += aliceValues[idx];
                flag = false;
            }else{
                bob += bobValues[idx];
                flag = true;
            }
        }

        if (alice != bob){
            return (alice > bob) ? 1 : -1;
        }else return 0;  
    }
};