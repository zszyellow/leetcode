class LRUCache 
{
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> MIPII;
    
    // cache datastructure to contain the data
    MIPII cache;
    // doubly linked list to track the recent used sequence
    LI used;
    int _capacity;
    
public:
    LRUCache(int capacity) 
    {
        this->_capacity = capacity;
    }
    
    int get(int key) 
    {
        auto it = this->cache.find(key);
        if (it == this->cache.end()) return -1;
        this->used.erase(it->second.second);
        this->used.push_front(key);
        it->second.second = used.begin();
        return it->second.first;   
    }
    
    void put(int key, int value) 
    {
        auto it = cache.find(key);
        if (it != cache.end()) 
        {
            this->used.erase(it->second.second);
            this->used.push_front(key);
            it->second.second = used.begin();
        }
        else 
        {
			if (cache.size() == _capacity) 
            {
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */