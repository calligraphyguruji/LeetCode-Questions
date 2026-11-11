class MinStack {
public:
    MinStack() { //this is constructor => if you don't study oops concepts
    //you don't have to write any code in here.
        
    }

    //1.) Initialize a empty stack
    stack<pair<int, int>> st; //stores {value, minValue}
    
    void push(int value) {
        
        int newMin = value;

        if(!st.empty()){

            newMin = min(value, getMin());//find minimum
        }

        st.push({value, newMin});
    }
    
    void pop() {
        
        st.pop();
    }
    
    int top() {
        
        return st.top().first; //return the value , because stack stores {value, minValue}
    }
    
    int getMin() {
        
        return st.top().second;//min value is already calculated in push func. ,just return the the second column minValue
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */