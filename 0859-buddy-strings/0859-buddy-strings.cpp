class Solution {
public:
    //Approach : Mismatch Index Tracking + Frequency Array

    //Time Complexity = O(n) =>
    /* We traverse the strings to check their lengths, equality, duplicate characters, and mismatched indices.
    * Each traversal takes O(n) time, where n is the length of the string.
    * Therefore, the overall time complexity is O(n).
    */

    //Space Complexity = O(1) =>
    /* The frequency array always contains 26 elements, requiring constant space. = O(1)
    * The indices vector stores at most two indices before returning false if a third mismatch is found.
    * Therefore, the auxiliary space complexity is O(1).
    */


    bool buddyStrings(string s, string goal) {
        
        int countSwaps = 0;

        //edge-case
        if(s.length() != goal.length()){
            return false;
        }

        
        if(s == goal){//if both strings are equal
            
            int freq[26] = {0};//array to store frequency

            // Traverse the string to find any duplicate character
            for(int i = 0; i < s.length(); i++){

                freq[s[i] - 'a']++;

                if(freq[s[i] - 'a'] > 1){ //more than 1 time, we can swap
                    return true;
                }
            }

            // No duplicate characters, so a swap cannot keep s unchanged
            return false;
        }

        vector<int> indices;

        for(int i = 0; i < s.length(); i++){

            if(s[i] != goal[i]){
                indices.push_back(i);
            }

            if(indices.size() > 2){//if more than 2 indices differ => return false
                return false;
            }
        }

        if(indices.size() != 2){ //also exactly 2 indices should differ if not then false
            return false;
        }
        
        //swap two indices in s & goal and then check if equal
        return s[indices[0]] == goal[indices[1]] &&
            s[indices[1]] == goal[indices[0]] ;
    }
};