class Solution {
public:
    //Time Complexity = O(n)
    //Space Complexity = O(n)
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int, int> m ;//to find index and val
        vector<int> ans ; //vector ans to store 

        for(int i=0 ; i<arr.size() ; i++){
            int first = arr[i] ;
            int second = tar - arr[i] ;

            if(m.find(second) != m.end()){ //to find : O(1)
                ans.push_back(i) ;
                ans.push_back(m[second]) ;
                break ;
            }
            //if not found
            m[first] = i ; //insert again first 

        }
        return ans ; //return the ans vector
    }
};