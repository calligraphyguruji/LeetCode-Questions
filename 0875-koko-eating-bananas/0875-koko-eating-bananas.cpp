class Solution {
public:
    //Approach : Binary Search on Answer

    //Time Complexity = O(n × log M) =>
    /* n = Number of banana piles.
    * M = Maximum bananas in a pile.
    * Binary Search: O(log M) → Search space is halved in each iteration.
    * For Loop: O(n) → Calculates total hours for all piles in each iteration.
    */

    //Space Complexity = O(1) =>
    /* Only a few variables (start, end, mid, totalHours) are used.
    * No additional data structures are created for storage.
    */

    int minEatingSpeed(vector<int>& piles, int h) {
        
        //1.) Initialize two pointers
        int start = 1; //minSpeed possible is 1
        int end = *max_element(piles.begin(), piles.end());//maxSpeed possible is max(piles)

        //2.) Traverse the Search space from start to end
        while(start <= end){

            int mid = start + (end - start)/2; //current eating speed

            //3.) Calculate total hours required
            long long totalHours = 0;

            for(int bananas : piles){
                totalHours += (bananas +(long long)mid-1 )/mid;
            }

            //4.) Check if Koko can finish within h hours

            //Case 1: Koko can finish within h hours
            if(totalHours <= h){
                
                end = mid-1; //search in left for smaller speed
            }

            //Case 2: Koko can't finish within h hours
            else if(totalHours > h){
                
                start = mid+1; //search in right for greater speed
            }
        }


        //5.) Return the minimum possible speed
        return start; 
    }
};