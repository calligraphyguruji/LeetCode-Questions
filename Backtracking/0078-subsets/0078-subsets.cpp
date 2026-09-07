class Solution {
public: 
    //Time Complexity = O(n * 2^n) => at every step there is two choices include or exclude for n elements.
    //Space Complexity = O(n * 2^n) => cause extra array used for storing elements and output array.
    void getAllSubsets(vector<int>&arr, vector<int>&ans, int i, vector<vector<int>> &allSubsets ){
        //base case
        if(i == arr.size()){
            //store subsets
            allSubsets.push_back({ans}) ;
            return ;
        }
        //inclusion
        ans.push_back(arr[i]) ;
        getAllSubsets(arr,ans,i+1,allSubsets) ;
        
        //Backtracking
        ans.pop_back() ;

        //exclusion
        getAllSubsets(arr,ans,i+1,allSubsets) ;
    }
     

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> allSubsets ; //to store all subsets
        vector<int> ans ;
        //function call to getAllSubsets
        getAllSubsets(arr,ans,0,allSubsets) ;

        return allSubsets ; //important to return allSubsets vector
    }
};