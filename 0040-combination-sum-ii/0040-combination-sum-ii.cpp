class Solution {
public:
    //Time Complexity = O(2^n * k) => O(2^n) cause for every step there is 2 choices
    //Space Complexity = O(k * n)
    void getCombinations(vector<int>& candidates, int target,vector<int> &curr, int idx, vector<vector<int>> &result){
        //edge case when target = -ve
        if(target < 0) return ; //cause chose wrong path (return)

        //base case
        if(target == 0){
            result.push_back(curr) ;
            return ;
        }

        //now check for each element
        for(int i = idx ; i<candidates.size() ; i++){
            if(i > idx && candidates[i] == candidates[i-1]){
                continue ; //skip checks for duplicate values
            }
            //push current element in curr vector
            curr.push_back(candidates[i]) ;

            //now explore for i+1
            getCombinations(candidates,target-candidates[i], curr, i+1, result) ;
            //Backtracking step : remove elements from curr (wapas aate time)
            curr.pop_back() ;

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result ; //to store all the ans vectors

        vector<int> curr ; //to store current array of selected elements

        //optimisaton to avoid duplicates
        sort(begin(candidates), end(candidates)) ;

        //function call to solve
        getCombinations(candidates,target,curr,0,result) ;

        return result ; //very important to return vector of all the ans
    }
};