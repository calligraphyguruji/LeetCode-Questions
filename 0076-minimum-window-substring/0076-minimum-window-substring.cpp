class Solution {
public:
    //Time Complexity = O(N) => cause traversing each char single time in s (n chars)
    //Space Complexity = O(1) => cause both mapT & mapS freq. vectors take constant space.
    bool contains(vector<int> &mapS, vector<int> &mapT){
        for(int i=0 ; i<256 ; i++){
            if(mapT[i] > mapS[i]){ //freq of mapT is greater then
                return false ; //freq not matched
            }
        }
        //if doesn't return false in above loop then
        return true ; 
    }
    string minWindow(string s, string t) {
        //two freq maps(vector)
        vector<int> mapT(256,0) ;
        vector<int> mapS(256,0) ;
       
       //fill mapT with all the chars. present in t
       for(char ch : t) mapT[ch]++ ;

       int left = 0 , right = 0 , minLength = INT_MAX , minStart = 0 ;

       //start making window and push that char in mapS
       for( ; right < s.length() ; right++){
          mapS[s[right]]++ ;

           //now compare mapT and mapS 
           while(contains(mapS,mapT)){
             if(right-left+1 < minLength){
                minLength = right-left+1 ;
                minStart = left ; //update minStart to reduce the size of window
             }
             mapS[s[left++]]-- ; //reduce the size from left
           }
       }
       
       //if minLength is still INT_MAX means no minLength found then return "" (empty substr)
       //else return substr of minlength
       return minLength == INT_MAX ? "" : s.substr(minStart,minLength) ;



    }
};