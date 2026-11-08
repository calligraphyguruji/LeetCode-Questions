class Solution {
public:
    //Approach : Stack-Based Evaluation

    //Time Complexity = O(n) =>
    /* We read each token once.
    * A number takes one stack push. An operator takes two pops, one calculation, and one push.
    * Each token takes constant time under the given constraints, so processing n tokens takes O(n) time.
    */
    
    //Space Complexity = O(n) =>
    /* The stack stores operands and intermediate results that are waiting to be used.
    * In the worst case, many numbers arrive before any operator. For example, in 1 2 3 4 + + +, all four numbers are on the stack before the first +.
    * The maximum stack size can grow in proportion to n, so the extra space is O(n).
    */


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