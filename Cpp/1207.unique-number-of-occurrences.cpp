class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash_map;
        for (int &num : arr) {
            if (hash_map.find(num) == hash_map.end()) hash_map[num] = 1;
            else hash_map[num] ++;
        }
        
        unordered_set<int> hash_set;
        for (auto &pair : hash_map) {
            if (hash_set.empty()) hash_set.insert(pair.second);
            else {
                if (hash_set.find(pair.second) != hash_set.end()) return false;
                else hash_set.insert(pair.second);
            }
        }
        return true;
    }
};