class Solution {
public:
    //Approach : Prefix Construction + Conditional Reversal

    //Time Complexity = O(n) =>
    /* We traverse the string character by character until ch is found or the string ends.
    * Reversing the prefix takes O(n) time in the worst case.
    * Therefore, the overall time complexity is O(n), where n is the length of the string.
    */

    //Space Complexity = O(n) =>
    /* We create a separate string ans to store the prefix.
    * In the worst case, ans stores all n characters of the string.
    * Therefore, the space complexity is O(n).
    */

    string reversePrefix(string word, char ch) {

        string ans; //to store the output
        
        bool rev = false; //to track if reverse needed

        for(int i = 0; i < word.length(); i++){
            
            //insert every character in ans until ch reached
            ans += word[i];

            if(word[i] == ch){ //ch found in word
                rev = true; //means you have to reverse the word till ch
                break;
            }
        }

        if(rev == true){
            //reverse the string
            reverse(ans.begin(), ans.end());

            ans += word.substr(ans.length());
        }
        else{
            return word;
        }
        
        //finally return the output
        return ans;
    }
};