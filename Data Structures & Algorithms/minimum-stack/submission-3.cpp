class MinStack {
    stack<int>s,minstack;
public:    
MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(minstack.empty()){minstack.push(val);
        return;
        }
        if(val<minstack.top())minstack.push(val);
        else minstack.push(minstack.top());
    }
    
    void pop() {
        s.pop();
        minstack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};