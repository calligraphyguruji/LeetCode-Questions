class Solution {
public: 
    //Time Complexity = O(n+n) = O(2n) = O(n) => cause traversing whole array 
    //Space Complexity = O(n) => cause using extra data structure => " stack " ;
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); //to store all nextG
        stack<int> st; //to find nextG
        //traverse 2 times for circular array
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop(); //remove elements lesser than current
            }
            //check if stack is empty then ans = -1
            //else ans = st.top() 
            if (i < n) {
                ans[i] = st.empty() ? -1 : st.top();
                //ternary statement for above checks
            }
            //push current element in the stack
            st.push(nums[i % n]);
        }

        return ans; //very important to return all the nextG vector
    }
};