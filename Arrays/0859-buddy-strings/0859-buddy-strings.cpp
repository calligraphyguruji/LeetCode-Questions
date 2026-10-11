class Solution {
public:
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