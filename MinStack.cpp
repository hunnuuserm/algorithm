//https://leetcode.cn/problems/min-stack/description/
//leetcode 155最小栈

class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if(minValStack.empty())
        {
            minValStack.push(val);
        }
        else
        {
            minValStack.push(min(minValStack.top(),val));
        }
    }
    
    void pop() {
        st.pop();
        minValStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minValStack.top();
    }
private:
    stack<int> st;
    stack<int> minValStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */