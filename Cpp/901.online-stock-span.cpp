class StockSpanner {
private:
    stack<int> prices_;
    stack<int> weights_;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int weight = 1;
        while (!prices_.empty() && prices_.top() <= price) {
            prices_.pop();
            weight += weights_.top();
            weights_.pop();
        }
        prices_.push(price);
        weights_.push(weight);
        return weight;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */