class MyQueue {
public: 
    //Time Complexity = O(n) = O(n) + O(1) + O(1) + O(1)
    //Space Complexity = O(n) => cause two stacks used
    
    //We will use two stacks
    stack<int> s1 ;
    stack<int> s2 ;

    MyQueue() { //constructor
        
    }
    
    void push(int x) { //Time Complexity = O(1)
        //Step 1 : s1 elements copy -> s2
        while(!s1.empty()){
            s2.push(s1.top()) ;
            s1.pop() ; //after copying into s2, pop from s1 
        }
        //Step 2 : s1.push(data)
        s1.push(x) ;
        
        //Step 3 : s2 elements copy -> s1
        while(!s2.empty()){
            s1.push(s2.top()) ;
            s2.pop(); //after copying into s1, pop from s2
        }

    }
    
    int pop() { //Time Complexity = O(1)
        int ans = s1.top() ;
        s1.pop();
        return ans ;
    }
    
    int peek() { //Time Complexity = O(1)
        return s1.top() ;//front
    }
    
    bool empty() { //Time Complexity = O(1)
        return s1.empty() ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */