/*
* just using one queue to implement the stack, move the last size-1 element to the front to generate the stack
*/

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        int n = q.size();
        //move the last val to the first position
        for (int i = 1; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
    
private:
    queue<int> q;
};
