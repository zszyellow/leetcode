class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> hm;
        for (auto &&piece : pieces) hm[piece[0]] = piece;
        for (int i = 0; i < arr.size(); ) {
            if (hm.find(arr[i]) == hm.end()) return false;
            else {
                int k = hm[arr[i]].size();
                vector<int> tmp(arr.begin()+i, arr.begin()+i+k);
                if (tmp != hm[arr[i]]) return false;
                i += k;
            }
        }
        return true;
    }
};