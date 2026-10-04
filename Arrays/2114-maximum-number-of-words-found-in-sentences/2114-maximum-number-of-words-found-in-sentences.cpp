class Solution {
public:
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