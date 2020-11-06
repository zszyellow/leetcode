class Bucket {
private:
    std::forward_list<pair<int, int>> fl_;
public:
    Bucket() : fl_() {}
    
    int get(int key) {
        auto it = std::find_if(fl_.begin(), fl_.end(), [&](const pair<int, int> &p) {
            return p.first == key;
        });
        return it == fl_.end() ? -1 : (*it).second;
    }
    
    void update(int key, int val) {
        auto it = std::find_if(fl_.begin(), fl_.end(), [&](const pair<int, int> &p) {
            return p.first == key;
        });
        if (it == fl_.end()) fl_.push_front({key, val});
        else (*it).second = val;
    }
    
    
    void erase(int key) {
        fl_.remove_if([&](const pair<int, int> &p) {
            return p.first == key;
        });
    }
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : key_range_(2069), buckets_(key_range_) {}
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int bucket_idx = this->hash(key);
        buckets_[bucket_idx].update(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int bucket_idx = this->hash(key);
        return buckets_[bucket_idx].get(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int bucket_idx = this->hash(key);
        buckets_[bucket_idx].erase(key);
    }
    
protected:
    int hash(int key) { return key % key_range_; }
    
private:
    const int key_range_;
    std::vector<Bucket> buckets_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */