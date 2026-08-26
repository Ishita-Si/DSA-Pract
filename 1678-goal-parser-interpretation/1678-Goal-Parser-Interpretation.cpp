class Solution {
public:
    string interpret(string command) {
        string k = "";
        int i = 0;
        int n = command.size();
        
        while(i < n){
            if(command[i] == 'G'){
                k.push_back('G');
                i++; 
            } else if(command[i] == '('){
                if(command[i+1] == ')'){
                    k.push_back('o'); 
                    i += 2;           
                } else if(command[i+1] == 'a'){
                    k += "al";        
                    i += 4;         
                }
            }
        }
        return k;
    }
};
