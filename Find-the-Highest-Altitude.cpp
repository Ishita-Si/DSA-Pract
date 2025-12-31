1class Solution {
2public:
3    int largestAltitude(std::vector<int>& gain) {
4        int max_altitude = 0;
5        int current_altitude = 0;
6        
7        for (int altitude_gain : gain) {
8            current_altitude += altitude_gain;
9            
10            if (current_altitude > max_altitude) {
11                max_altitude = current_altitude;
12                
13            }
14        }
15        
16        return max_altitude;
17    }
18};