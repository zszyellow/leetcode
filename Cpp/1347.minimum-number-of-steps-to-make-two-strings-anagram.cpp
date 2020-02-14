/*
 * @lc app=leetcode id=1347 lang=cpp
 *
 * [1347] Minimum Number of Steps To Make Two Strings Anagram
 */

class Solution {
public:
    int minSteps(string s, string t) {
        int res = 0;
        unordered_map<char, int> hash_map_s;
        unordered_map<char, int> hash_map_t;
        
        for (char ss : s) {
            hash_map_s[ss] ++;
        }
        for (char tt : t) {
            hash_map_t[tt] ++;
        }
        
        for (auto &&kv : hash_map_t) {
            auto key = kv.first;
            auto val = kv.second;
            if (hash_map_s.find(key) == hash_map_s.end()) {
                res += val;
            } else if (val > hash_map_s[key]) {
                res += val - hash_map_s[key];
            }
        }
        return res;
    }
};
