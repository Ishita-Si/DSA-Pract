1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        if (s.size() != goal.size()) return false;
5        return (s + s).find(goal) != string::npos;
6    }
7};