class StockSpanner {
public:
    //Time Complexity = O(n) => next func. call for n elements.
    //Amortized Time Complexity= O(1) 
    //Space Complexity = O(n) => cause using stack to store n elements.
    stack<pair<int,int>> st; //stack pair to store [price, span]

    StockSpanner() {
    }

    int next(int price) {
        int span = 1; //because at min. span = 1 for every price
        //if stack is not empty then check top <= price
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second; //add in span
            st.pop();//pop values lesser than current
        }
        //store (price,span) in the stack
        st.push({price, span});
        return span;
    }
    //in above st.top().first means the price => st[first, second] => st[price, span]
    //st.top().second means the span cause st[price, span]
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */