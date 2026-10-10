class Solution {
public:
    //Approach : String Traversal with Space Counting

    //Time Complexity = O(n) =>
    /* We traverse the string s at most once, where n = no. of elements.
    */

    //Space Complexity = O(n) =>
    /* The ans string stores the truncated sentence.
    * atmost n elements.
    */


    string truncateSentence(string s, int k) {
        
        string ans;//to store the output

        int countWords = 0;

        for(int i = 0; i < s.length(); i++){

            if(s[i] == ' '){ //found space then
                
                countWords++;

                if(countWords == k){ //when reached to k
                    break;
                }
            }

            ans += s[i]; 
        }


        //finally return the output
        return ans;

    }
};