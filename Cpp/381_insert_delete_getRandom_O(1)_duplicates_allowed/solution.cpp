class RandomizedCollection {
private:
    vector<int> v;
    unordered_map<int, unordered_set<int>> h;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = (h.find(val) == h.end());
        h[val].insert(v.size());
        v.push_back(val);
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (h.find(val) == h.end()) return false;
        int tmp = v.back();
        v.pop_back();
		h[tmp].erase(v.size());
		if (tmp != val) {
			int _id = *h[val].begin(); 
			h[val].erase(_id);
			h[tmp].insert(_id);
			v[_id] = tmp;
		}
		if (h[val].empty()) h.erase(val);
		return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */