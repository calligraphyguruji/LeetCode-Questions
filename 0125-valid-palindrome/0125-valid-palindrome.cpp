class Solution {
public:
    //Approach : Two Pointers (Opposite Direction) with Alphanumeric Filtering
 
    //Time Complexity = O(n) =>
    /* Two Pointers: start and end traverse the string from opposite ends.
    * Alphanumeric Check: isAlphaNumeric() takes O(1) time per character.
    * Character Comparison: tolower() takes O(1) time.
    * Total: Each character is processed at most once → O(n).
    */

    //Space Complexity = O(1) =>
    /* Two Pointers: Only start and end variables are used.
    * In-place Processing: No additional string, array, or data structure is created.
    * Total: O(1) auxiliary space.
    */


    bool isAlphaNumeric(char ch){
        //if char is from 0-9 and a to z => alphanumeric
        if( (ch >= '0' && ch <= '9') ||
            (tolower(ch) >= 'a' && tolower(ch) <= 'z') ){
                return true;
        }
        
        //else
        return false;

    }
    bool isPalindrome(string s) {
        
        //edge-case : if empty string
        if(s.empty()){
            return true;
        }

        
        int n = s.length();
        int start = 0;
        int end = n-1;

        while(start < end){//here st == end is not required

            //Skip non-alphanumeric chars.
            if(!isAlphaNumeric(s[start])){
                start++;
                continue;
            }
            if(!isAlphaNumeric(s[end])){
                end--;
                continue;
            }

            //If curr char. matched then check next char
            //s[start] with s[end] => move start & end
            if(tolower(s[start]) == tolower(s[end])){
                start++;
                end--;
            }
            else{
                return false;
            }
        }

        //if full string processed and no false found
        return true;
    }
};