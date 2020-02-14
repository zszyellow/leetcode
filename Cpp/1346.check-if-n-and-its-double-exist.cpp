/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < arr.size(); i ++) {
            if (hash_map.find(arr[i]*2) != hash_map.end()) {
                return true;
            } else if (arr[i] % 2 == 0 && hash_map.find(arr[i]/2) != hash_map.end()) {
                return true;
            } else {
                hash_map[arr[i]] == i;
            }
        }
        return false;
    }
};
