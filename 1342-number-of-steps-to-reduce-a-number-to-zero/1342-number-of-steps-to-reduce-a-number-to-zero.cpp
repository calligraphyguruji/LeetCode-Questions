class Solution {
public:
    int numberOfSteps(int num) {
        
        int steps = 0;//to count steps

        while(num){ 
            
            if(num % 2 == 0){ //if even num
                num /= 2; //divide by 2
                steps++; //count 1 step
            }
            else{ //odd
                num -= 1; //subtract 1
                steps++;
            }
            
        }
        
        //finally return the output
        return steps;
    }
};