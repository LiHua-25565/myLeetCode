class MinStack {
    stack<int> value_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int value) {
        value_stack.push(value);
        int cur_min = min_stack.top();
        if(value<cur_min) min_stack.push(value);
        else min_stack.push(cur_min);
    }
    
    void pop() {
        value_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return value_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
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