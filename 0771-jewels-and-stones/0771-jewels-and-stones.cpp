class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        int n = stones.size();

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