class Solution {
public:
    bool checkString(string s) {

        //Step 1: Initialize boolean variable seen_b = false.
        bool seen_b = false;

        //Step 2: Traverse string character by character from index 0 to n - 1.
        for(char ch : s){
            //Step 3: If character is 'b', set seen_b = true.
            if(ch == 'b'){
                seen_b = true;
            }

            //Step 4: If character is 'a' and seen_b == true, return false.
            if(ch == 'a' && seen_b == true){
                return false;
            }
        }

        //Step 5: Return true after loop completes.
        //Because if no false returned it means true
        return true;

    }
};