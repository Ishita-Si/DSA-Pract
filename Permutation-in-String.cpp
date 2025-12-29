1class Solution {
2public:
3    bool checkInclusion(string s, string t) {
4        if (s.size() > t.size()) return false;
5
6        vector<int> freqS(26, 0), freqW(26, 0);
7
8        // count characters of s
9        for (char c : s) {
10            freqS[c - 'a']++;
11        }
12
13        int k = s.size();
14
15        // first window
16        for (int i = 0; i < k; i++) {
17            freqW[t[i] - 'a']++;
18        }
19
20        if (freqS == freqW) return true;
21
22        // slide the window
23        for (int i = k; i < t.size(); i++) {
24            freqW[t[i] - 'a']++;          // add new char
25            freqW[t[i - k] - 'a']--;      // remove old char
26
27            if (freqS == freqW) return true;
28        }
29
30        return false;
31    }
32};
33