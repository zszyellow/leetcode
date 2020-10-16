class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        /* brute force, TC: O(N^2), SC:O(N) */
//         vector<int> res;
        
//         for (int i = 0; i < arr.size(); ++ i) {
//             int greatest = i == arr.size()-1 ? -1 : INT_MIN;
//             for (int j = i + 1; j < arr.size(); ++ j) {
//                 greatest = std::max(greatest, arr[j]);
//             }
//             res.push_back(greatest);
//         }
//         return res;
        
        /* Loop from back, TC: O(N), SC: O(N) */
        vector<int> res(arr.size(), 0);
        res[arr.size()-1] = -1;
        int greatest = INT_MIN;
        for (int i = arr.size()-1; i >= 0; -- i) {
            if (i != arr.size()-1) {
                res[i] = greatest;    
            }
            greatest = std::max(greatest, arr[i]);
        }
        return res;
    }
};