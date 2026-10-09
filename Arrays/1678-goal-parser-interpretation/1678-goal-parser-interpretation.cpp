class Solution {
public:
    string interpret(string command) {
        
        string ans; //to store the output

        //traverse in command string
        for(int i = 0; i < command.length(); i++){

            //check conditions: G, (), (al)
            if(command[i] == 'G'){
                ans += "G";
            }
            
            if(command[i] == '(' && command[i+1] == ')'){
                ans += "o";
            }

            if(command[i] == '(' && command[i+1] == 'a'){
                ans += "al";
            }
        }


        //finally return the output
        return ans;
    }
};