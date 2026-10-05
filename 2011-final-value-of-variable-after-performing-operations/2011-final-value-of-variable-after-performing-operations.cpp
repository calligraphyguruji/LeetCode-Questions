class Solution {
public:
    //Approach : Brute Force(Nested Loop) / String Traversal + Character Checking

    //Time Complexity = O(N) =>
    /* * Let N be the number of operations.
    * For each operation, we traverse its string.
    * Each operation has a fixed length of 3 characters, so checking it takes O(1).
    * Therefore: O(N × 3) = O(N)
    */

    //Space Complexity = O(1) =>
    /* We only use the variable ans and loop variables.
    * No extra array or data structure is created.
    */

    int finalValueAfterOperations(vector<string>& operations) {
        
        int ans = 0;//initial value is zero

        for(int i = 0; i < operations.size(); i++){

           if(operations[i].find('+') != string::npos){ //string::npos means not found here => != string::npose means found
             ans++; //increment
           }
           else{ // means '-' found => decrement
            ans--; //decrement
           }
        }

        //finally return the output
        return ans;
    }
};