class Solution {
public:
    //Time Complexity = O(3^T * klogM) 
    // O(3^T) => because each i has 3 choices => 3*3*3*.....T times 
    // O(klogM) => in set each valid combinations insert + comparison
    //Optimisation => to encounter duplicate ans
    set<vector<int>> s ;
    void getAllCombinations(vector<int>& arr,int idx,vector<int> &combin,vector<vector<int>> &ans, int tar){
        //base cases
        if(idx == arr.size() || tar < 0) return ;
        if(tar == 0){
            if(s.find(combin) == s.end()){
             ans.push_back(combin) ;
             s.insert(combin) ; //very important to store in set
            }
            return ;
        }
        combin.push_back(arr[idx]) ;
        //single time inclusion
        getAllCombinations(arr,idx+1,combin,ans,tar-arr[idx]) ;
        //multiple time inclusion
        getAllCombinations(arr,idx,combin,ans,tar-arr[idx]) ;
        //Backtracking
        combin.pop_back() ;
        //exclusion
        getAllCombinations(arr,idx+1,combin,ans,tar) ;
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans ;//to store all the ans combinations
        vector<int> combin ; //to store one combination

        //function call to calculate combination sums
        getAllCombinations(arr,0,combin,ans,target) ;

        return ans ;//very important condition to return all the ans
    }
};