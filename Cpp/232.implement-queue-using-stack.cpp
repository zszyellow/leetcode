/* Push(): O(N), Pop(): O(1) */
// class MyQueue {
// private:
//     stack<int> st1;
//     stack<int> st2;
// public:
//     /** Initialize your data structure here. */
//     MyQueue() {
        
//     }
    
//     /** Push element x to the back of queue. */
//     void push(int x) {
//         while (!st1.empty()) {
//             st2.push(st1.top());
//             st1.pop();
//         }
//         st2.push(x);
//         while (!st2.empty()) {
//             st1.push(st2.top());
//             st2.pop();
//         }
//     }
    
//     /** Removes the element from in front of queue and returns that element. */
//     int pop() {
//         int res = st1.top();
//         st1.pop();
//         return res;
//     }
    
//     /** Get the front element. */
//     int peek() {
//         return st1.top();
//     }
    
//     /** Returns whether the queue is empty. */
//     bool empty() {
//         return st1.empty();
//     }
// };

/* Push(): O(1) Pop(): Amortized O(1) */
class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
    int front;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        front = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (st1.empty()) {
            front = x;
        }
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int res = st2.top();
        st2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (!st2.empty()) {
            return st2.top();
        }
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
};
