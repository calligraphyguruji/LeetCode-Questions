class Solution {
public:
    bool isAlphaNumeric(char ch){
        //if char is from 0-9 and a to z => alphanumeric
        if( (ch >= '0' && ch <= '9') ||
            (tolower(ch) >= 'a' && tolower(ch) <= 'z') ){
                return true;
        }
        
        //else
        return false;

    }
    bool isPalindrome(string s) {
        
        //edge-case : if empty string
        if(s.empty()){
            return true;
        }

        
        int n = s.length();
        int start = 0;
        int end = n-1;

        while(start < end){//here st == end is not required

            //Skip non-alphanumeric chars.
            if(!isAlphaNumeric(s[start])){
                start++;
                continue;
            }
            if(!isAlphaNumeric(s[end])){
                end--;
                continue;
            }

            //If curr char. matched then check next char
            //s[start] with s[end] => move start & end
            if(tolower(s[start]) == tolower(s[end])){
                start++;
                end--;
            }
            else{
                return false;
            }
        }

        //if full string processed and no false found
        return true;
    }
};