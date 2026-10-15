class Solution {
public:
    //Time Complexity = O(nlogn) = O(nlogn) for sorting + O(n) for traversing
    //Space Complexity = O(1) => no extra data structure used.
    
    string longestCommonPrefix(vector<string>& strs) {
        string result = "" ; //make an empty string to store the results

        //edge case : if no char matched return empty string
        if(strs.empty()) return "" ;

        //Step 1 : sort the strings
        sort(strs.begin(), strs.end()) ;

        //Step 2 : compare first and last 
        string first = strs.front() ;
        string last = strs.back() ;

        for(int i=0 ; i<first.length() ; i++){
            if(i >= first.length() || first[i] != last[i])
               break ; //when char. not matched stop comparing

            result += first[i] ; //add matched chars. in result string   
        }

        return result ; //very important to return the ans.

    }
};