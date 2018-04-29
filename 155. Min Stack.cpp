class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    vector<int> minstack;
    MinStack() {}
    
    void push(int x) {
        if(minstack.empty()){
            minstack.push_back(x);
        }else{
            int minTop = minstack.back();
            minstack.push_back(min(x, minTop));
        }
        stack.push_back(x);
    }
    
    void pop() {
        stack.pop_back();
        minstack.pop_back();
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return minstack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */