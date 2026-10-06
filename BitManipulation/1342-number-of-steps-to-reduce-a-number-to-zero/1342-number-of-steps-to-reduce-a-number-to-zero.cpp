class Solution {
public:

    //Approach : Simulation / Iterative Reduction

    //Time Complexity = O(log N) =>
    /* In each step, num either:
    * decreases by 1 if odd
    * becomes num / 2 if even
    * After an odd number is reduced by 1, it becomes even and is then divided by 2.
    * Therefore, the number of operations grows logarithmically with num.
    */

    //Space Complexity = O(1) =>
    /* We only use steps and num.
    * No extra data structures are used.
    */


    int numberOfSteps(int num) {
        
        int steps = 0;//to count steps

        while(num){ 
            
            if(num % 2 == 0){ //if even num
                num /= 2; //divide by 2
                steps++; //count 1 step
            }
            else{ //odd
                num -= 1; //subtract 1
                steps++; //count 1 step
            }
            
        }
        
        //finally return the output
        return steps;
    }
};