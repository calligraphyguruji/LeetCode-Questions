class Solution {
public:
    //Approach : Optimised(Direct Simulation with a Single-Pass Group Scan)

    //Time Complexity = O(n * R) =>
    /* Each round scans the current string once.
    * Although there are nested loops, i only moves forward: each digit is processed once per round.
    * Building result takes at most O(n) per round.
    * Therefore, each round costs O(n), giving O(n × R) across all rounds. Actual work decreases as the string gets shorter.
    */

    //Space Complexity = O(n) =>
    /* `ans` stores the next string and needs at most O(n) space.
    * i, sum, and count use O(1) space.
    * Therefore, total auxiliary space is O(n).
    */


    string digitSum(string s, int k) {
        
        // Step 6: Repeat rounds while the length exceeds k.
        while(s.size() > k){

            // Step 1: Start this round with an empty result string.
            string ans;

            // Step 2: Begin at the first unprocessed character.
            int i = 0;

            while(i < s.size()){

                int sum = 0;
                int count = 0;

                // Step 3: Read at most k digits, stopping if s ends.
                while(count < k && i < s.size()){

                    // Step 4: Add this digit and advance to the next one.
                    sum += s[i] - '0';
                    i++;
                    count++;
                }

                // Append the complete sum of this group.
                ans += to_string(sum);
            }

            // Step 5: Replace s and repeat only if its length exceeds k.
            s = ans;
        }

        //Finally the length is now less than or equal to k.
        return s;

    }
};