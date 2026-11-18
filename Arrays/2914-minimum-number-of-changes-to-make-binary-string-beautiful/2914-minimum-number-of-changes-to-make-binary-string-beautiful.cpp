class Solution {
public:
    int minChanges(string s) {
        
        //1.) Initialize a change counter to 0.
        int count = 0; //It stores the total minimum cost.

        //2.) Traverse the string two positions at a time.
        //Start at index 0, then visit 2, 4, and so on.
        for(int i = 0; i < s.length(); i += 2){

            //3.)Compare the current character with the next character.
            if(s[i] != s[i+1]){

                count++;//4.) If they differ, increase the counter by 1.
            }
        }

        //5.) Return the counter.
        return count;
    }
};