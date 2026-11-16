class Solution {
public:
    string digitSum(string s, int k) {
        
        // Step 5: Repeat rounds while the length exceeds k.
        while(s.size() > k){

            // Step 1: Split s into consecutive groups of at most k digits.
            vector<string> groups;

            for(int i = 0; i < s.size(); i += k){
                // substr automatically handles a smaller last group.
                groups.push_back(s.substr(i, k));
            }

            // Step 2: Calculate the digit sum of this group.
            vector<string> sums;

            for(string& group : groups){

                int sum = 0;

                for(char digit : group){
                    
                    sum += digit - '0'; // Convert character to integer.
                }
                // Step 3: Store the complete sum as a string.
                sums.push_back(to_string(sum));
            }

            // Step 4: Join all replacement strings in order.
            string next;

            for(string& sumString : sums){
                
                next += sumString;
            }

            // Use the completed string for the next round.
            s = next;
        }

        //Finally the length is now less than or equal to k.
        return s;

    }
};