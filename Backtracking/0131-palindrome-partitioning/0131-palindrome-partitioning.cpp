class Solution {
public:
    //Time Complexity = O(n* 2^n) => total partitions = 2^n-1
    // O(n) => n palindromes , O(2^n) => recursion tree for total partitions
    bool isPalindrome(string s){
        string s2 = s ; //make a copy s2
        reverse(s2.begin(), s2.end()) ; //reverse s2 for comparison

        return s == s2 ; //only returns true when s == s2 reverse
    }
    void getAllParts(string s,vector<string> &partitions, vector<vector<string>>&ans){
        //base case
        if(s.size() == 0){
            ans.push_back(partitions) ;
            return ;
        }

        //make cuts on the string
        for(int i=0 ; i<s.size(); i++){
            string part = s.substr(0,i+1) ; //make cuts

            if(isPalindrome(part)){ //if part is palindrome
                partitions.push_back(part) ;//then add in partitions
                //function call for next parts
                getAllParts(s.substr(i+1), partitions,ans) ;
                //Backtracking 
                partitions.pop_back() ;//to make a new fresh part next time
            }
        }

    }

   //don't ever try to change the name of this given function
    vector<vector<string>> partition(string s) {
        vector<string> partitions ;//to store 1 partition
        vector<vector<string>> ans ; //to store all the ans strings
        //helper function call
        getAllParts(s, partitions, ans) ;

        return ans ; //very important to return all the ans strings
    }
};