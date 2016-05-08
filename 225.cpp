/*
* using two queues to generate the stack
*/

class Stack {
public:
    
    queue<int> q1, q2;
    int fq = 1;
    
    // Push element x onto stack.
    void push(int x) {
        if (fq == 1) q1.push(x);
        else q2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        move();
        if (fq == 1) q2.pop();
        else q1.pop();
    }

    // Get the top element.
    int top() {
        move();
        int res;
        if (fq == 1) {
            res = q2.front();
            q2.pop();
            q1.push(res);
        } else {
            res = q1.front();
            q1.pop();
            q2.push(res);
        }
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return (q1.empty() && q2.empty());
    }
    
    void move() {
        if (q1.empty()) {
            fq = 1;
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
        } else {
            fq = 2;
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
};
