class Solution {
public:
    string sortSentence(string s) {
        
        vector<string> arr(10);

        string temp;//to store the output

        //traverse the input string
        for(int i = 0; i <= s.length(); i++){
           
           //count a word when a space is seen
           //or end of the string reached
           if(i == s.length() || s[i] == ' '){
                
                int pos = temp.back() - '0'; //find correct position to place the word
                temp.pop_back(); //make place

                arr[pos] = temp; //place at correct pos

                temp.clear(); 
           }
           else{
                temp += s[i];
           }
            
        }

        string ans; //to store the output

        for(int i = 1; i <= 9; i++){ //1-indexed word position

            if(!arr[i].empty()){// Check if the current position contains a word

                if(!ans.empty()){
                    ans += ' ';// Add a space before the word if ans already contains a word
                }
                
                ans += arr[i];// Append the current word to the output string
            }
        }

        //finally return the output
        return ans;
    }
};