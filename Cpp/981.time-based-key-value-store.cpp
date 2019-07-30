/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */
class TimeMap {
private:
    unordered_map<string, map<int, string>> tm;
public:
    /** Initialize your data structure here. */
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        tm[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = tm[key].upper_bound(timestamp);
        return it == tm[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

