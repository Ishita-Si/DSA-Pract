1class Solution {
2public:
3    string defangIPaddr(string address) {
4        string ip = "";
5        for(char c : address){
6            if(c == '.'){
7                ip.push_back('[');
8                ip.push_back(c);
9                ip.push_back(']');
10            }else{
11               ip.push_back(c); 
12            }
13        }
14        return ip;
15    }
16};