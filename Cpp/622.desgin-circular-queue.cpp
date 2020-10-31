class MyCircularQueue {
private:
    int limit_;
    int cnt_;
    int front_;
    int rear_;
    vector<int> buffer_;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        limit_ = k;
        cnt_ = 0;
        front_ = k-1;
        rear_ = 0;
        buffer_ = vector<int>(k, 0);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (cnt_ == limit_) return false;
        buffer_[rear_] = value;
        rear_ = (rear_ + 1) % limit_;
        cnt_++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!cnt_) return false;
        front_ = (front_ + 1) % limit_;
        cnt_ --;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (!cnt_) return -1;
        return buffer_[(front_ + 1) % limit_];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (!cnt_) return -1;
        return buffer_[(rear_ - 1 + limit_) % limit_];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return cnt_ == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return cnt_ == limit_;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */