class Solution {
public:
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