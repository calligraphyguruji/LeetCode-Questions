class Solution {
public:
    //Approach : Hashing using unordered_set

    //Time Complexity = O(n) =>
    /* Traversing n elements using for loop.
    * If input size is n then output function grows like n.
    */

    //Space Complexity = O(n) =>
    /* Unordered_set is used for storage.
    * It can store upto n elements in worst case.
    */

    bool containsDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        unordered_set<int> distinct; //set always stores unique values
        
        for(int i = 0; i < n; i++){
            
            //check if already found in set => duplicate
            if(distinct.count(nums[i])){
                return true;
            }

            //otherwise insert in set
            distinct.insert(nums[i]);
              
        }

        //finally if no true found in abovec checks
        return false;
       
    }
};