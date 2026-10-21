class MinStack {
public:
stack<int> st;
stack<int> help;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(help.size() == 0 || help.top() >= value) help.push(value);
    }
    
    void pop() {
        if(st.top() == help.top()) {
            help.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return help.top();
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