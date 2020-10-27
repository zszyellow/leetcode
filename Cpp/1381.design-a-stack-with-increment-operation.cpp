class CustomStack {
    vector<int> v;
    int maxSize;
    
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (v.size() < maxSize) v.push_back(x);
    }
    
    int pop() {
        if (v.empty()) return -1;
        int res = v.back();
        v.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        int n = v.size(), i = 0;
        while (k > 0 && i < n) {
            v[i] += val;
            i ++;
            k --;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */