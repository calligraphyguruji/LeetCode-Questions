class Solution {
public:
    //Approach : Greedy (Hash Map + Sorting)

    //Time Complexity = O(n * logn) =>
    /* Count frequencies: O(n) to build unordered_map.
    * Sort hand: O(n * logn) where n = hand.size().
    * Greedy matching: Each card belongs to exactly one group of size groupSize.
    * Total inner-loop decrements across whole run = n steps -> O(n).
    * Dominant factor: Sorting -> O(n * logn).
    */

    //Space Complexity = O(n) =>
    /* unordered_map stores frequency of at most N unique elements -> O(n).
    * std::sort takes auxiliary stack space -> O(log n).
    * Total auxiliary space: O(n).
    */


    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        //Step 1 (Early Exit): Check hand.size() % groupSize == 0. If not, return false
        if(hand.size() % groupSize != 0){
            return false;
        }

        //Step 2 (Frequency Count): Store frequencies in hash map unordered_map<int, int> count.
        unordered_map<int, int> freq;

        for(auto& card : hand){
            freq[card]++;
        }

        //Step 3: Sort hand in ascending order.
        sort(hand.begin(), hand.end());

        //Step 4 (Greedy Matching): Iterate through sorted hand. For each card 
        for(auto& card : hand){
            //If Freq[x] == 0, card already used in previous group; continue.
            if(freq[card] == 0){
                continue;
            }

            int count = freq[card];

            for(int i = 0; i < groupSize; i++){
                
                int nextCard = card + i;

                if(freq[nextCard] < count){ //Insufficient frequency
                    return false;// Missing required consecutive card
                }

                freq[nextCard] -= count; //Subtract count from each card + i;
            }
        }

        //Finally if no false found in above it means true
        return true;

    }
};