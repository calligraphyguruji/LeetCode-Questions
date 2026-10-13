class Solution {
public:
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