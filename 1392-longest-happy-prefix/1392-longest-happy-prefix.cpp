class Solution {
public:
    int ComputeLPS(string& s){
        vector<int> lps(s.size(),0) ;

        for(int i=1 ; i<s.size() ; i++){
            int j = lps[i-1] ; //length of previous longest prefix suffix
            
            if(s[i] == s[j]){ //when matched 
                lps[i] = j+1 ; //every time ans += 1 ;
            }

            else{
                while(j > 0 && s[i] != s[j]){
                    j-- ; //go back to when previously matched
                    j = lps[j] ;
                }
                if(s[i] == s[j]) //check from prev matched if matched
                   lps[i] = j+1 ; //then prev ans += 1

            }
        }

        return lps[s.size()-1] ;

    }
    string longestPrefix(string s) {
        //very important to return the LPS string.
        return s.substr(0,ComputeLPS(s)) ;
    }
};