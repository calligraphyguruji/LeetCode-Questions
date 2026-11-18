class Solution {
public:
    //Approach : Greedy (Count Mismatched Adjacent Pairs)

    //Time Complexity = O(n) =>
    /* The loop moves by 2, so it runs n / 2 times.
    * Each iteration compares two characters and may increment the counter—both take O(1) time.
    * Total: O(n / 2) = O(n).
    */

    //Space Complexity = O(1) =>
    /* Only two integer variables, count and i, are used.
    * No additional data structures are created.(like arrays, stacks, queue etc.)
    * Their memory usage stays constant as the input grows.
    */

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