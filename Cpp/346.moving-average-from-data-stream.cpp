class MovingAverage {
private:
    queue<int> window; 
    int size;
    int cur_sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        this->cur_sum = 0;
    }
    
    double next(int val) {
        if (window.size() < this->size) {
            cur_sum += val;
            window.push(val);
            return static_cast<double>(this->cur_sum) / this->window.size();
        } else {
            int to_pop = window.front();
            window.pop();
            window.push(val);
            cur_sum = cur_sum - to_pop + val;
            return static_cast<double>(this->cur_sum) / this->size; 
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */