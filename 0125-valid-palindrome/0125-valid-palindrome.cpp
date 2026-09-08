class Solution {
public:
    bool isAlphanumeric(char ch){
        //check if ch is between (a-z) or (0-9)
        if( (ch >= '0' && ch <= '9') || 
        (tolower(ch) >= 'a' && tolower(ch) <= 'z') ){
            return true ;

        }
        return false ;

    }
    bool isPalindrome(string s) {
       
       int st = 0 , end = s.length()-1 ;

       while( st < end){ //here st = end is not required
         if(!isAlphanumeric(s[st])){
            st++ ; continue ;
         }
         if(!isAlphanumeric(s[end])){
            end-- ; continue ;
         }
         if(tolower(s[st]) != tolower(s[end]) ){
            return false ;//if match not found
         }
         st++ ; end-- ;

       }
       //if match found(while loop doesn't executed)
       return true ;

    }
};