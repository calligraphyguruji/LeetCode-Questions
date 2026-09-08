class Solution {
public:
    //isFreqSame function to check same idx (freq, windFreq)
    bool isFreqSame(int freq1[] , int freq2[] ){
        for(int i=0 ; i<26 ; i++){
            if(freq1[i] != freq2[i] ){
                return false ;
            }
        }
        return true ;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0} ; //freq array to store freq of idx in s1

        for(int i=0 ; i<s1.length() ; i++){
            freq[s1[i] - 'a'] ++ ;
        }
        
        int windSize = s1.length() ;

        for(int i=0 ; i<s2.length() ; i++){
            int windIdx = 0 , idx = i ;
            int windFreq[26] = {0} ; 
            //window freq array to store search s1 in s2

            //check if windIdx not greater than windSize 
            //and also idx not greater than s2.length()
            while(windIdx < windSize && idx < s2.length() ){
                windFreq[s2[idx] - 'a']++ ;
                windIdx++ ; idx++ ;

            }
            if(isFreqSame(freq,windFreq) ){ //if found same 
                return true ;
            }
        }
        return false ; //if not found same 

    }
};