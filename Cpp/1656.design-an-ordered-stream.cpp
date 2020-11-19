class OrderedStream {
public:
    OrderedStream(int n) : ptr(1), container(n+1) {}
    
    vector<string> insert(int id, string value) {
        vector<string> res;
        container[id] = value;
        
        if (id == ptr) {
            while (ptr < container.size() && !container[ptr].empty()) {
                res.push_back(container[ptr++]);
            }
        }        
        
        return res;
    }
private:
    int ptr;
    vector<string> container;
};
