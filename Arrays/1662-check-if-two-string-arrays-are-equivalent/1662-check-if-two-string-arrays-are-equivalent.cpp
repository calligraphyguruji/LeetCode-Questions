class Solution {
public:
    //Approach : String Concatenation and Comparison

    //Time Complexity = O(n + m) => Where : n = size of word1, m = size of word2
    /* We traverse word1 and concatenate all its strings into firstWord, taking O(n) time.
    * We traverse word2 and concatenate all its strings into secondWord, taking O(m) time.
    * We compare firstWord and secondWord, taking O(min(n, m)) in the worst case when their lengths are equal.
    */


    //Space Complexity = O(n + m) => 
    /* firstWord stores all characters from word1, requiring O(n) space.
    * secondWord stores all characters from word2, requiring O(m) space.
    * The comparison uses O(1) auxiliary space.
    */


    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string firstWord; 
        string secondWord;

        //traverse in word1 and make a string firstWord
        for(int i = 0; i < word1.size(); i++){
            
            firstWord += word1[i];
        }
       
        //traverse in word2 and make a string secondWord
        for(int i = 0; i < word2.size(); i++){
            
            secondWord += word2[i];
        }
         
        //compare firstWord and secondWord
        if(firstWord == secondWord){//if same string
            return true;
        }
        
        return false; //if not same string
        
    }
};