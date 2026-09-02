class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stopChange[1001] = {0}; 
        
        for (const auto& trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];
            
            stopChange[start] += passengers;
            stopChange[end] -= passengers;
        }
        
        int currentPassengers = 0;
        for (int i = 0; i <= 1000; i++) {
            currentPassengers += stopChange[i];
            
            if (currentPassengers > capacity) {
                return false;
            }
        }
        
        return true;
    }
};