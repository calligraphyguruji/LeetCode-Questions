class Solution {
public:
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