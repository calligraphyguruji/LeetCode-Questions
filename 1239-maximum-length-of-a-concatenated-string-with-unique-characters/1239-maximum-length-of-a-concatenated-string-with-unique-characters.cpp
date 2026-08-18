class Solution {
public:

    bool hasDuplicates(string& s1, string& s2){
        //take array of 26 chars. 
        int arr[26] = {0} ;//to store frequency of chars.

        //check in s1 if repeating chars.
        for(char &ch : s1){
            if(arr[ch - 'a'] > 0){ //repeating
                return true ;
            }
            else{ //if not repeating push in freq array
                arr[ch - 'a']++ ; 
            }
        }


        //check in s2 if repeating chars.
        for(char &ch : s2){
            if(arr[ch - 'a'] > 0){
                return true ;
            }
        }


        //finally if no duplicates found in above checks
        return false ;


    }
    int solve(int i, vector<string>& arr, string temp, int n){
        //base-case : if index out of bound then return temp
        if(i >= n){
            return temp.length() ;
        }

        int include = 0 ;
        int exclude = 0 ;

        if(hasDuplicates(arr[i], temp)){
            exclude = solve(i+1, arr, temp, n) ; //just move i
        }

        else{ //two choices : exclude, include
            exclude = solve(i+1, arr, temp, n) ;
            include = solve(i+1, arr, temp+arr[i], n) ;
        }

        return max(include, exclude) ;
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size() ;

        string temp = "" ; //empty string
        int i = 0 ; 

        return solve(i, arr, temp, n) ;

        
    }
};