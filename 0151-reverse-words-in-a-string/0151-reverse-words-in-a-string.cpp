class Solution {
public:
    //Time Complexity = O(n)
    //Space Complexity = O(n) => ans storing the output
    string reverseWords(string s) {
       int n = s.length() ;
       string ans = "" ;
       //Step 1 : reverse the words position
       reverse(s.begin(),s.end()) ;

       for(int i=0 ; i<n ; i++){
         string word = "" ;//to store the word

         while(i < n && s[i] != ' '){
            word += s[i] ;
            i++ ;
        }

        //Step 2 : reverse the individual word
        reverse(word.begin(), word.end()) ;

        //add the word in the ans string
        if(word.length() > 0){
            ans += " " + word ;
        }
       }
       //to remove the extra space in the first position(0th idx)
       return ans.substr(1) ; //substring starts from 1st idx 
    }
};