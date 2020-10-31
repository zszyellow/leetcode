class MyCircularDeque {
private:
    int limit_;
    int cnt_;
    int front_;
    int rear_;
    vector<int> buffer_; // simulated ring buffer
    
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        limit_ = k;
        cnt_ = 0;
        front_ = k - 1;
        rear_ = 0;
        buffer_ = vector<int>(k, 0);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (cnt_ == limit_) return false;
        buffer_[front_] = value;
        front_ = (front_ - 1 + limit_) % limit_;
        cnt_++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (cnt_ == limit_) return false;
        buffer_[rear_] = value;
        rear_ = (rear_ + 1) % limit_;
        cnt_ ++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (!cnt_) return false;
        front_ = (front_ + 1) % limit_;
        cnt_ --;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (!cnt_) return false;
        rear_ = (rear_ - 1 + limit_) % limit_;
        cnt_ --;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (!cnt_) return -1;
        return buffer_[(front_ + 1) % limit_];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (!cnt_) return -1;
        return buffer_[(rear_ - 1 + limit_) % limit_];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cnt_ == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cnt_ == limit_;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */