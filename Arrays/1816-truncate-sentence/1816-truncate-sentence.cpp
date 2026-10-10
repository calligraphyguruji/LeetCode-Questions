class Solution {
public:
    string truncateSentence(string s, int k) {
        
        string ans;//to store the output

        int countWords = 0;

        for(int i = 0; i < s.length(); i++){

            if(s[i] == ' '){ //found space then
                
                countWords++;

                if(countWords == k){
                    break;
                }
            }

            ans += s[i];
        }


        //finally return the output
        return ans;

    }
};