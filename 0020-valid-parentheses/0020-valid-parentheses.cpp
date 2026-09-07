class Solution {
public:
    //Time Complexity = O(n) => cause traversing n brackets
    //Space Complexity = O(n) => at most we will store n brackets in the stack.
    bool isValid(string str) {
        //make a stack of char
        stack<char> st ;

        //traverse the string 
        for(int i=0 ; i<str.size() ; i++){ // push opening brackets in stack
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                st.push(str[i]) ;
            }

            else{ //match with closing brackets
                //edge case : when closing brackets are more
                if(st.empty()){
                    return false ;
                }

                //check the opening bracket on the stack top and match with string current bracket
                if((st.top() == '(' && str[i] == ')') ||
                   (st.top() == '{' && str[i] == '}') ||
                   (st.top() == '[' && str[i] == ']')){
                    
                    st.pop() ; //if matched then pop from stack
                }

                else{ //not matched
                  return false ;

                }

            }

        }

        //very important to return true if stack is empty
        //this means all the matched element are popped
        return st.empty() ;

    }
};