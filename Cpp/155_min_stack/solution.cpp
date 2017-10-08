class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> seq; 
    int min = INT_MAX;
    
    MinStack() {
        seq.clear();
    }
    
    void push(int x) {
        seq.push_back(x);
        min = std::min(x, min);
    }
    
    void pop() {
        if (seq.size() == 1) min = INT_MAX;
        else if (seq.back() == min) min = *std::min_element(seq.begin(), seq.begin()+seq.size()-1);
        seq.pop_back();
    }
    
    int top() {
        return seq.back();
    }
    
    int getMin() {
        return min;
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