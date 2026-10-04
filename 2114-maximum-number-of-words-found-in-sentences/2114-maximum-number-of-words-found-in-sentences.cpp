class Solution {
public:
    //Approach : Brute Force (String Traversal + Space Counting)

    //Time Complexity = O(N) =>
    /* Let N be the total number of characters across all sentences.
    * We visit every character once. => N chars = O(N)
    * For each character, we check whether it is a space.
    */

    //Space Complexity = O(1) =>
    /* We only use few extra variables.
    * No extra array or data structure is created.
    */


    int mostWordsFound(vector<string>& sentences) {
              
        int maxCount = 0;

        //traverse in sentences
        for(int i = 0; i < sentences.size(); i++){
            
            int count = 1; //to store the output
            
            for(int j = 0; j < sentences[i].size(); j++){
                
                if(sentences[i][j] == ' '){ //if empty space found
                    count++;//one word found
                }
            }

            //udpate maxCount if greater count found
            if(maxCount < count){
                maxCount = count;
            }
        }


        //finally return the output
        return maxCount;
    }
};