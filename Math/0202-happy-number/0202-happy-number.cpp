class Solution {
public:
    bool isHappy(int n) {
        
        //1.) Store previously visited numbers
        unordered_set<int> visited;

        //2.) Repeat until n becomes 1
        while(n != 1){

            //if n repeats, a cycle exists
            if(visited.count(n)){
                return false;
            }

            //3.) Mark current number as visited
            visited.insert(n);

            //4.) Calc. sum of squares of digits
            int sqSum = 0;

            while(n > 0){

                int digit = n % 10;
                sqSum += digit*digit;
                n /= 10;
            }

            //5.) Update n
            n = sqSum;
        }

        //6.) Reached 1 -> Happy Number
        return true;
    }
};