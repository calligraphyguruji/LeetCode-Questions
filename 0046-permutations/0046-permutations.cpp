class Solution {
public: //Time Complexity = O(n * n!)
    void getPermutations(vector<int> &arr, int idx, vector<vector<int>> &ans){
        //base case 
        if(idx == arr.size()){
            //store in the ans
            ans.push_back({arr}) ;
            return ;
        }

        //unique choices
        for(int i = idx ; i<arr.size() ; i++){
            //swap idx place => (i)th choice
            swap(arr[idx],arr[i]) ;
            getPermutations(arr, idx+1, ans) ;// to get next permutations
            //Backtracking : change to avoid duplicate 
            swap(arr[idx], arr[i]) ;
        }

    }

    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> ans ;

        //function call to getPermutations
        getPermutations(arr,0,ans) ;

        return ans ; //very important to return the ans : All permutations

    }
};