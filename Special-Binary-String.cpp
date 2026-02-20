1class Solution {
2public:
3    string makeLargestSpecial(string s) {
4        vector<string> specials;
5
6        int start = 0;
7        int sum = 0;
8
9        for(int i = 0; i < s.length(); i++) {
10            sum += s[i] == '1' ? 1 : -1;
11
12            if(sum == 0) {
13                string inner = s.substr(start+1, i-start-1);
14                specials.push_back("1" + makeLargestSpecial(inner) + "0");
15                start = i+1;
16            }
17        }
18
19
20        sort(begin(specials), end(specials), greater<string>());
21
22        string result;
23        for(string &str : specials) {
24            result += str;
25        }
26
27        return result;    
28    }
29};