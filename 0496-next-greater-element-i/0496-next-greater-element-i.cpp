class Solution {
public:
    //Time Complexity = O(n+m) => O(n) for loop over nums1 , O(m) for loop over nums2 .
    //Space Complexity = O(n+m) => O(n) for stack and map , O(m) for storing m elements in ans .
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //Step 1 : find nums2 -> nextGreater and store in unordered map
        //Step 2 : nums1 -> nextGreater using map values 

        unordered_map<int, int> m ; //to store [nums2[i], nextG]
        stack<int> s ;//to find nums2 -> nextGreater

        for(int i=nums2.size()-1 ; i>= 0 ; i--){
            while(s.size() > 0 && s.top() <= nums2[i]){
                s.pop() ; //pop elements in stack lesser than current

            }
            //if stack is empty nextG = -1 ;
            if(s.empty()){
                m[nums2[i]] = -1 ;
            }
            else{ //if not empty
                m[nums2[i]] = s.top() ; //s.top is nextG
            }
            //push current element in stack
            s.push(nums2[i]) ;
        }
        //ans vector 
        vector<int> ans ; //to store nextG of nums1

        for(int i=0 ; i<nums1.size() ; i++){
            ans.push_back(m[nums1[i]]) ;
        }

        return ans ;//very important to return all nextG vector
    }
};