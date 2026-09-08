class MinStack {
public:
    stack<long long int> s ;
    long long minVal ;
    MinStack() {
        
    } //this is constructor
    
    //Time Complexity = O(n) => overall performing n operations
    //Space Complexity = O(n)

    void push(int val) { //Time Complexity of push = O(1)
        //Case(1) :
        if(s.empty()){
            s.push(val) ;
            minVal = val ;
        }
        //Case(2) :
        else{
            if(val < minVal){
                s.push((long long)2*val - minVal) ;
                minVal = val ;
            }
            else{
                s.push(val) ;
            }
        }
    }
    
    void pop() { //Time Complexity = O(1)
        if(s.top() < minVal){
            minVal = 2*minVal - s.top() ;
        }
        s.pop() ; //values greater than minVal
    }
    
    int top() {//Time Complexity = O(1)
        //Case 1: top is formula value
        if(s.top() < minVal){
            return minVal ;
        }
        //Case 2 :
        else{
            return s.top() ;
        }
    }
    
    int getMin() { //Time Complexity = O(1)
        return minVal ; //optimization
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */