class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        //1.) Initialize a empty stack
        stack<int> st;

        //2.) Read tokens from left to right
        for(string& token : tokens){
            
            //3.) if the token is number push into stack
            if(token != "+" && token != "-" && token != "*" && token != "/"){

                //convert into integer
                //push it
                st.push(stoi(token)); //stoi = converts string into int
                continue;
            }

            //4.) if the token is an operator
            
            int right = st.top();
            st.pop();

            int left = st.top();
            st.pop();

            // Evaluate the operation and push its result.
            if(token == "+"){
                st.push(left + right);
            }
            else if(token == "-"){
                st.push(left - right);
            }
            else if(token == "*"){
                st.push(left * right);
            }
            else{ //if token == "/"
                st.push(left / right);
            }
            
        }

        //5.) Return the answer
        return st.top();
    }
};