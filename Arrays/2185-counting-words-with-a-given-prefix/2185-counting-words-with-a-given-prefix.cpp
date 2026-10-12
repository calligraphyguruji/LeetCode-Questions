class Solution {
public:
    //Approach : String Search Using find()

    //Time Complexity = O(n * m) =>
    /* O(n × m), where n is the number of words and m is the maximum word length.
    */

    //Space Complexity = O(1) =>
    /* No extra data structure used for storage.
    * Only a few variables used.
    */

    int prefixCount(vector<string>& words, string pref) {
        
        int countPrefix = 0;

        //traverse in words
        for(int i = 0; i < words.size(); i++){

            if(words[i].find(pref) == 0){//if found in words
                countPrefix++;
            }
        }
        
        //finally return the output
        return countPrefix;
    }
};