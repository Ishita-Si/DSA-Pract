1class Solution {
2public:
3    int romanToInt(string s) {
4        unordered_map<char,int> map = {
5            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D', 500},{'M',1000}
6        };
7
8        int integer = 0;
9        for(int i = 0; i < s.size(); i++){
10            if(i+1 < s.size() && map[s[i]]<map[s[i+1]]){
11                integer -= map[s[i]];
12            }else{
13                integer += map[s[i]];
14            }
15        }
16        return integer; 
17    }
18};