
/*
* add an attribute for each element to store the current minimul value.
*/

class MinStack {
public:
    typedef pair<int, int> elem;
    vector<elem> stack;
    
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (stack.empty()) stack.push_back(make_pair(x,x));
        else {
            int minx = stack.back().second;
            stack.push_back(make_pair(x, x < minx ? x : minx));
        }
    }
    
    void pop() {
        if (!stack.empty()) stack.pop_back();
    }
    
    int top() {
        if (!stack.empty())
            return stack.back().first;
        return 0;
    }
    
    int getMin() {
        if (!stack.empty())
            return stack.back().second;
        return 0;
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
