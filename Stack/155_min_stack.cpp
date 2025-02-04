class MinStack {
private:
    stack<pair<int, int>> s;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty() || val < s.top().second) s.push({val, val});
        else s.push({val, s.top().second});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {  
        return s.top().second;
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

// revised - 02/03/2025