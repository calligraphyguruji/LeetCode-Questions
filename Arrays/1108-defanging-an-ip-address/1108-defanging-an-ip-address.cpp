class Solution {
public:
    //Approach : String Traversal + Character Replacement

    //Time Complexity = O(n) =>
    /* We traverse the address string once. [ n elements = O(n) ]
    * Each character is processed in constant time.
    * s += "[.]" adds a fixed-size string of 3 characters, so it is effectively O(1).
    * So : O(n) * O(1) = O(n)
    */

    //Space Complexity = O(n) =>
    /* We create a new string s to store the defanged IP address.
    * string s stores up to n chars.
    */


    string defangIPaddr(string address) {
        
        //ans string to store the output in defanged version
        string s;

        //traverse in adress and         
        for(int i = 0; i < address.length(); i++){
            
            //check if '.' found then covert it
            //'.' = [.]
            if(address[i] == '.'){ // '' used for single character
                s += "[.]"; // "" used for string
            }
            else{
                s.push_back(address[i]);
            }
        }

        //finally return the output
        return s;
    }
};