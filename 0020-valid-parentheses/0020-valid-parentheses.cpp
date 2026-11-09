class Solution {
public:
    bool isValid(string s) {
        
        //1.) Initialize empty stack
        stack<char> brackets;

        //2.) Traverse the string from left to right
        for(int i = 0; i < s.size(); i++){

            //push each opening bracket into the stack
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                
                brackets.push(s[i]);
                continue;
            }

            //3.) Check each closing bracket

            if(brackets.empty()){
                return false; //if no opening brackets in stack
            }

            //if exists closing brackets
            if(brackets.top() == '(' && s[i] == ')' ||
                brackets.top() == '{' && s[i] == '}' ||
                brackets.top() == '[' && s[i] == ']'){
                    
                    brackets.pop();//4.)if matching closing brackets found
            }
            else{//if not matching
                return false;
            }
        }
        
        //5.) Finally return the output
        return brackets.empty(); //if all matched then it should be true otherwise false
        
    }
};