class Solution {
public:
    //Approach : String Traversal with Conditional Matching

    // Time Complexity = O(n) =>
    /*
    * Traverse the command string once.
    * Each character is processed in constant time.
    * n = length of the command string.
    */

    // Space Complexity = O(n) =>
    /*
    * The ans string stores the interpreted output.
    * In the worst case, the output length is proportional to n.
    */

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