class Solution {
public:
    //Approach : Greedy + Math

    //Time Complexity = O(1) =>
    /* No loops are used.
    */

    //Space Complexity = O(1) =>
    /* No extra data structures are used for storage.
    * Only a few variables are used. = O(1)
    */

    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        //1.) Find the shared quantity
        long long shared = min(need1, need2);

        //2.) Calc. the shared cost
        long long sharedCost = shared * min(costBoth, cost1 + cost2);

        //3.) Find the remaining requirements
        long long remaining1 = need1 - shared;
        long long remaining2 = need2 - shared;

        //4.) Calc. the remaining costs
        long long remainCost1 = remaining1 * min(costBoth, cost1);
        long long remainCost2 = remaining2 * min(costBoth, cost2);


        //5.) Return the total cost including shared + remaining
        return sharedCost + remainCost1 + remainCost2;

    }
};