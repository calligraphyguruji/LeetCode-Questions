class Solution {
public:
    //Approach : Hash Map / Frequency Lookup

    //Time Complexity = O(J + S) =>
    /*
    There are two loops:
    1. Loop through jewels:
        * Runs J times → O(J)
    2. Loop through stones:
        * Runs S times → O(S)
        * Hash map lookup mp[c] is O(1) on average.
    */

    //Space Complexity = O(J) =>
    /* We store each unique jewel character in the hash map.
    * There can be at most J entries.
    */

    int numJewelsInStones(string jewels, string stones) {

        unordered_map<char, bool> mp;//to store ...

        //first store all jewels
        for(char c : jewels){
            mp[c] = true;
        }
        
        // Check each stone and count jewels
        int count = 0;

        for(char c : stones){
            
            //check if stone is found in map that means it is a jewel
            //because only jewels were stored in map
            if(mp[c]){  
                count++;
            }
        }

        //finally return the output
        return count;

    }
};