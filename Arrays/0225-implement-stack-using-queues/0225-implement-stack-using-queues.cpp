class MyStack {
public:
    //Time Complexity = O(n) = O(n) + O(1) + O(1) + O(1) 
    //Space Complexity = O(n) => cause using two extra queues

    
    //we will use two queues
    queue<int> q1 ;
    queue<int> q2 ;

    MyStack() { //constructor
        
    }
    
    void push(int x) { //Time Complexity = O(n)
        //Step 1 : q1 elements copy -> q2
        while(!q1.empty()){
            q2.push(q1.front()) ;
            q1.pop() ; //after copying pop from q1 
        }
        //Step 2 : q1.push(data) 
        q1.push(x) ;

        //Step 3 : q2 elements copy -> q1 (reverse)
        while(!q2.empty()){
            q1.push(q2.front()) ;
            q2.pop() ; //after copying into q1 pop from q2
        }

    }
    
    int pop() { //Time Complexity = O(1)
        int ans = q1.front() ;
        q1.pop() ;
        return ans ;
    }
    
    int top() { //Time Complexity = O(1)
        return q1.front() ; //q1 front is stack top
    }
    
    bool empty() { //Time Complexity = O(1)
        return q1.empty() ;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */