class Solution {
public:

    //Approach : Two-Pointer Traversal with Remaining String Concatenation

    //Time Complexity = O(n + m) =>
    /* n = length of word1
    * m = length of word2
    * The loop runs min(n, m) times, adding one character from each string in every iteration.
    * The remaining characters are appended using substr(), which takes time proportional to the number of remaining characters.
    */

    //Space Complexity = O(n + m) =>
    /* The ans string stores the merged characters from both input strings.
    * In the worst case, the result contains all n + m characters.
    */

    string mergeAlternately(string word1, string word2) {

       string ans;//to store the output

       int n = min(word1.length(), word2.length());

       for(int i = 0; i < n; i++){         
          //add alternate in the ans
          ans += word1[i];
          ans += word2[i];
       }

       //if word1 finished but word2 remaining
       if(word1.length() > n){
          ans += word1.substr(n); //substr = substring
       }

       //if word2 finished but word1 remaining       
       if(word2.length() > n){
          ans += word2.substr(n); //substr = substring
       }

       //finally return the output
       return ans;
    }
};