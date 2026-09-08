class Solution {
public: 
    //Time Complexity = O(nlogn + n * 2^n) =>
    // O(nlogn) => sort, O(n * 2^n) => n times for 2^n subsets
    void getAllSubsets(vector<int> &arr, vector<int>&ans, int i , vector<vector<int>>&allSubsets){
        //base case 
        if(i == arr.size()){
            //store the ans
            allSubsets.push_back({ans}) ;
            return ;
        }

        //inclusion
        ans.push_back(arr[i]) ;
        getAllSubsets(arr, ans, i+1, allSubsets) ;

        //Backtracking
        ans.pop_back() ;

        //exclusion
        int idx = i+1 ;
        while(idx < arr.size() && arr[idx] == arr[idx-1]){
            idx++ ; //to skip until equal values 
        }
        getAllSubsets(arr, ans, idx, allSubsets) ;


    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        //Step 1 : sort (to avoid duplicate subsets)
        sort(arr.begin(), arr.end()) ;

        vector<vector<int>> allSubsets ; //to store allSubsets
        vector<int> ans ; //to store 1 ans at a time
       
        //function call to getAllSubsets
        getAllSubsets(arr, ans, 0, allSubsets) ;
        return allSubsets ; //very important to return allSubsets
    }
};