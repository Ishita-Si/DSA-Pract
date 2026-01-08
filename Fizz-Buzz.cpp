1class Solution {
2public:
3    vector<string> fizzBuzz(int n) {
4        vector<string> result;
5
6        for (int i = 1; i <= n; i++) {
7            if (i % 15 == 0) {
8                result.push_back("FizzBuzz");
9            } 
10            else if (i % 3 == 0) {
11                result.push_back("Fizz");
12            } 
13            else if (i % 5 == 0) {
14                result.push_back("Buzz");
15            } 
16            else {
17                result.push_back(to_string(i));
18            }
19        }
20
21        return result;
22    }
23};