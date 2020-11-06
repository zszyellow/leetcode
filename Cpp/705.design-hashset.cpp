class Bucket {
private:
    forward_list<int> fl_;
public:
    Bucket() : fl_() {}
    
    void insert(int key) {
        if (find(fl_.begin(), fl_.end(), key) == fl_.end()) {
            fl_.push_front(key);   
        }
    }
    
    void erase(int key) {
        fl_.remove(key);
    }
    
    bool contains(int key) {
        return find(fl_.begin(), fl_.end(), key) != fl_.end();
    }
};

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : key_range_(769), buckets_(key_range_) {}
    
    void add(int key) {
        int bucket_idx = this->hash(key);
        buckets_[bucket_idx].insert(key);
    }
    
    void remove(int key) {
        int bucket_idx = this->hash(key);
        buckets_[bucket_idx].erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int bucket_idx = this->hash(key);
        return buckets_[bucket_idx].contains(key);
    }
    
protected:
    int hash(int key) {
        return key % key_range_;    
    }
    
private:
    const int key_range_; // the base of modulo
    vector<Bucket> buckets_;
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */