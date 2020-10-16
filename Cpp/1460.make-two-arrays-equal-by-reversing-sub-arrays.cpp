class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> arr_cnts(1001, 0), target_cnts(1001, 0); 
        for (int i = 0; i < target.size(); ++ i) {
            arr_cnts[arr[i]] ++;
            target_cnts[target[i]] ++;
        }
        
        for (int i = 0; i < 1001; ++ i) {
            if (arr_cnts[i] != target_cnts[i]) return false;
        }
        return true;
    }
};