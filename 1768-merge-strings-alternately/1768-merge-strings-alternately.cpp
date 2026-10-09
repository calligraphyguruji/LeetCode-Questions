class Solution {
public:
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