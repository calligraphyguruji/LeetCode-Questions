class Solution {
public:
    //Time Complexity = O(n) => for traversing on array
    //Space Complexity = O(1) => extra bucket array but of constant(26 chars.)
    //very much easy problem
    bool isAnagram(string s, string t) {
        //edge case
        if(s.length() != t.length()) return false ;

        int bucketArray[26] = {0} ; //bucket array to store freq.

        //traverse the string
        for(int i=0 ; i<s.length() ; i++){
            bucketArray[ s[i] -'a']++ ; //++ for string 1
            bucketArray[ t[i] -'a']-- ; //-- for string 2
        }

        //check in bucketArray freq. stored
        for(int b : bucketArray){
            if(b != 0)
              return false ; //if freq. > 0 return false 
        }

        //otherwise
        return true ;
    }
};