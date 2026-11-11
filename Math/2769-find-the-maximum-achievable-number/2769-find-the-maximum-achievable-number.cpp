class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        
        // Step 1: Each operation can close the gap by 2:
        // increase num by 1 and decrease x by 1.
        int gap = 2;

        // Step 2: Calculate the largest gap closed in t operations.
        int maxGap = gap * t;

        // Step 3: Find the largest starting value of x.
        int x = num + maxGap;

        //Step 4 : Return the answer
        return x;
        
    }
};