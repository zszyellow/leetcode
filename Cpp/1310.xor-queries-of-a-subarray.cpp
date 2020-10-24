class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int m = arr.size(), n = queries.size();
        vector<int> prefix(m, arr[0]);
        for (int i = 1; i < m; ++ i) prefix[i] = prefix[i-1] ^ arr[i];
        
        vector<int> res;
        for (auto q : queries) {
            res.push_back(arr[q[0]] ^ prefix[q[0]] ^ prefix[q[1]]);
        }
        return res;
    }
};