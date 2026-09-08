class Solution {
public:
    //Time Complexity = O(n)
    //Space Complexity = O(n) => cause 2 extra vectors used.
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size() ;
        vector<int> left(n, 0) ; //to store left smaller(nearest)
        vector<int> right(n, 0) ; //to store right smaller(nearest)
        stack<int> s ; //to calc right, left smaller
        
        //Right smaller : using next greater element approach
        //Time Complexity = O(n) => cause same element pushed once and popped once so O(n+n) = O(2n) = O(n) (stack operations)
        //Not O(n^2) just because of nested loops.
        for(int i=n-1 ; i>=0 ; i--){
            while(!s.empty() && ht[s.top()] >= ht[i]){
                s.pop() ; //pop values greater than current
            }
            //check if stack is empty then right small= n => cause when no right smaller exist we have to move till n.
            //else right small = s.top()
            right[i] = s.empty() ? n : s.top() ;//ternary statement for above checks
            //push index of current element in the stack
            s.push(i) ; //for next comparisons

        }
        
        //Optimisation : before going to calc. left small pop extra vaues
        while(!s.empty()){
            s.pop() ;
        }

        //Left smaller : using previous smaller approach
        //Time Complexity = O(n) => cause same element pushed once and popped once so O(n+n) = O(2n) = O(n) (stack operations)
        //Not O(n^2) just because of nested loops.
        for(int i=0 ; i<n ; i++){
            while(!s.empty() && ht[s.top()] >= ht[i]){
                s.pop() ; //pop values greater than current
            }

            //check if stack is empty then left small = -1
            //else left small = s.top() 
            left[i] = s.empty() ? -1 : s.top() ;//ternary statement for above checks

            //push current element in the stack
            s.push(i) ; //for next comparisons
        }


        //Final ans to calc. largest area in histogram
        int ans = 0 ;
        
        for(int i=0 ; i<n ; i++){
            int width = right[i] - left[i] - 1 ;
            int currArea = ht[i] * width ;
            ans = max(ans, currArea) ;
        }

        return ans ; //very important to return the ans before submitting the code
    }
};