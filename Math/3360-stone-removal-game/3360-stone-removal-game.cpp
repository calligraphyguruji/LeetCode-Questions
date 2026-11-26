class Solution {
public:
    //Approach : Turn-by-Turn Simulation

    //Time Complexity = O(1) =>
    /* The loop runs at most 10 times: the required removal starts at 10 and decreases by 1 each turn.
    */

    //Space Complexity = O(1) =>
    /* The algorithm uses only a few variables (need and aliceTurn), regardless of n.
    */

    bool canAliceWin(int n) {
        
        //1.) Initialize: Set the required removal to 10 and mark Alice as the current player.
        int need = 10;
        bool Alice = true;

        //2.) Check whether the move is possible
        //If fewer stones remain than the required amount,
        // the current player loses.
        while(n >= need){
            //3.) Make the move: Subtract the required amount from the pile.
            n -= need;

            //4.) Prepare the next turn: Decrease the required amount by one and switch players.
            need -= 1;
            Alice = !Alice; //Bob's turn
        }

        //5.) Return the result: Alice wins if Bob is the player who cannot move.
        return !Alice;
    }
};