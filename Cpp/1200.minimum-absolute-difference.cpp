class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        for (int i = 0; i < arr.size()-1; ++ i) {
            min_diff = std::min(min_diff, arr[i+1] - arr[i]);
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < arr.size()-1; ++ i) {
            if (min_diff == arr[i+1]-arr[i]) res.push_back({arr[i], arr[i+1]});
        }
        return res;
    } 
};